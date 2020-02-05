//
//

// Include Files
#include <cmath>
#include <limits>
#include "ImageSimulation.h"
#include "ImageSimulationHeader.h"
#include <fstream>

	// image simulation with 3 PSFs
ImageSimulation::ImageSimulation(cv::Mat PSF_1, cv::Mat PSF_2, cv::Mat PSF_3, real magnification, real rmsOptAxis) :
	mPSF_1(PSF_1),
	mPSF_2(PSF_2),
	mPSF_3(PSF_3),
	mMagnification(magnification),
	mRMSradius(rmsOptAxis)
{
	mImageSimulation = ImgSimMain();
}

// Variable Definitions
omp_nest_lock_t emlrtNestLockGlobal;
static const double dv0[65] = { 1.0, 0.99879545620517241, 0.99518472667219693,
  0.989176509964781, 0.98078528040323043, 0.970031253194544, 0.95694033573220882,
  0.94154406518302081, 0.92387953251128674, 0.90398929312344334,
  0.881921264348355, 0.85772861000027212, 0.83146961230254524,
  0.80320753148064494, 0.773010453362737, 0.74095112535495922,
  0.70710678118654757, 0.67155895484701833, 0.63439328416364549,
  0.59569930449243336, 0.55557023301960218, 0.51410274419322166,
  0.47139673682599764, 0.42755509343028208, 0.38268343236508978,
  0.33688985339222005, 0.29028467725446233, 0.24298017990326387,
  0.19509032201612825, 0.14673047445536175, 0.0980171403295606,
  0.049067674327418015, 0.0, -0.049067674327418015, -0.0980171403295606,
  -0.14673047445536175, -0.19509032201612825, -0.24298017990326387,
  -0.29028467725446233, -0.33688985339222005, -0.38268343236508978,
  -0.42755509343028208, -0.47139673682599764, -0.51410274419322166,
  -0.55557023301960218, -0.59569930449243336, -0.63439328416364549,
  -0.67155895484701833, -0.70710678118654757, -0.74095112535495922,
  -0.773010453362737, -0.80320753148064494, -0.83146961230254524,
  -0.85772861000027212, -0.881921264348355, -0.90398929312344334,
  -0.92387953251128674, -0.94154406518302081, -0.95694033573220882,
  -0.970031253194544, -0.98078528040323043, -0.989176509964781,
  -0.99518472667219693, -0.99879545620517241, -1.0 };

static const double dv1[65] = { 0.0, 0.049067674327418015, 0.0980171403295606,
  0.14673047445536175, 0.19509032201612825, 0.24298017990326387,
  0.29028467725446233, 0.33688985339222005, 0.38268343236508978,
  0.42755509343028208, 0.47139673682599764, 0.51410274419322166,
  0.55557023301960218, 0.59569930449243336, 0.63439328416364549,
  0.67155895484701833, 0.70710678118654757, 0.74095112535495922,
  0.773010453362737, 0.80320753148064494, 0.83146961230254524,
  0.85772861000027212, 0.881921264348355, 0.90398929312344334,
  0.92387953251128674, 0.94154406518302081, 0.95694033573220882,
  0.970031253194544, 0.98078528040323043, 0.989176509964781, 0.99518472667219693,
  0.99879545620517241, 1.0, 0.99879545620517241, 0.99518472667219693,
  0.989176509964781, 0.98078528040323043, 0.970031253194544, 0.95694033573220882,
  0.94154406518302081, 0.92387953251128674, 0.90398929312344334,
  0.881921264348355, 0.85772861000027212, 0.83146961230254524,
  0.80320753148064494, 0.773010453362737, 0.74095112535495922,
  0.70710678118654757, 0.67155895484701833, 0.63439328416364549,
  0.59569930449243336, 0.55557023301960218, 0.51410274419322166,
  0.47139673682599764, 0.42755509343028208, 0.38268343236508978,
  0.33688985339222005, 0.29028467725446233, 0.24298017990326387,
  0.19509032201612825, 0.14673047445536175, 0.0980171403295606,
  0.049067674327418015, 0.0 };

// Function Declarations
static void b_celling(const emxArray_real_T *imageArray, double PSF_grid_factor,
	emxArray_cell_wrap_0 *M);
static void b_conv2(const emxArray_real_T *a, const emxArray_creal_T *b,
	emxArray_creal_T *c);
static void b_floor(emxArray_real_T *x);
static void b_ifftshift(creal_T x[16384]);
static void b_interpImg(const creal_T im[9], double ratio, emxArray_creal_T *out);
static double b_mod(double x, double y);
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384]);
static void b_zone(const emxArray_real_T *Obj, double r1, double r2, double c1,
	double c2, emxArray_real_T *f);
static void c_interpImg(const emxArray_creal_T *im, double ratio,
	emxArray_creal_T *out);
static void c_r2br_r2dit_trig(const creal_T x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384]);
static void conv2(const emxArray_real_T *a, const emxArray_real_T *b,
	emxArray_real_T *c);
static void eml_fftshift(creal_T x[16384], int dim);
static void eml_ifftshift(double x[16384], int dim);
static void ifftshift(double x[16384]);
static void meshgrid(const emxArray_real_T *x, const emxArray_real_T *y,
	emxArray_real_T *xx, emxArray_real_T *yy);
static void padarray(const creal_T varargin_1[16384], const double varargin_2[2],
	emxArray_creal_T *b);
static void r2br_r2dit_trig(const double x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384]);
static void r2br_r2dit_trig_impl(const creal_T x[16384], int xoffInit, const
	double costab[65], const double sintab[65], creal_T y[128]);
static void rot90(const double A[16384], double B[16384]);
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
OPD ImageSimulation::calculateOPD()
{
	mOPD = OPD();

	return mOPD;
}





//
// Arguments    : const emxArray_real_T *imageArray
//                double PSF_grid_factor
//                emxArray_cell_wrap_0 *M
// Return Type  : void
//
static void b_celling(const emxArray_real_T *imageArray, double PSF_grid_factor,
	emxArray_cell_wrap_0 *M)
{
	double r3;
	double c3;
	int i;
	int j;
	r3 = std::ceil((double)imageArray->size[0] / PSF_grid_factor);
	c3 = std::ceil((double)imageArray->size[1] / PSF_grid_factor);
	i = M->size[0] * M->size[1];
	M->size[0] = (int)PSF_grid_factor;
	M->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_0(M, i);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			b_zone(imageArray, ((1.0 + (double)i) - 1.0) * r3 + 1.0, (1.0 + (double)i)
				* r3, ((1.0 + (double)j) - 1.0) * c3 + 1.0, (1.0 + (double)j) * c3,
				M->data[j + M->size[0] * i].f1);
		}
	}
}

//
// Arguments    : const emxArray_real_T *a
//                const emxArray_creal_T *b
//                emxArray_creal_T *c
// Return Type  : void
//
static void b_conv2(const emxArray_real_T *a, const emxArray_creal_T *b,
	emxArray_creal_T *c)
{
	boolean_T p;
	emxArray_creal_T *b_c;
	emxArray_real_T *b_a;
	emxArray_creal_T *b_b;
	boolean_T guard1 = false;
	int firstRowA;
	int aidx;
	int cBegin;
	int cEnd;
	int cBegin1;
	int cEnd1;
	int ma;
	int na;
	int mc;
	int firstColB;
	int lastColB;
	int firstRowB;
	int lastRowB;
	int iC;
	int i;
	int lastColA;
	int k;
	int b_i;
	int a_length;
	int cidx;
	int r;
	int b_firstColB;
	int iA;
	int iB;
	int c_i;
	p = (a->size[0] == 1);
	emxInit_creal_T1(&b_c, 1);
	emxInit_real_T1(&b_a, 1);
	emxInit_creal_T1(&b_b, 1);
	guard1 = false;
	if (p) {
		p = (b->size[0] == 1);
		if (p) {
			firstRowA = a->size[1];
			aidx = b_a->size[0];
			b_a->size[0] = firstRowA;
			emxEnsureCapacity_real_T1(b_a, aidx);
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_a->data[aidx] = a->data[a->size[0] * aidx];
			}

			firstRowA = b->size[1];
			aidx = b_b->size[0];
			b_b->size[0] = firstRowA;
			emxEnsureCapacity_creal_T1(b_b, aidx);
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_b->data[aidx] = b->data[b->size[0] * aidx];
			}

			aidx = b_c->size[0];
			b_c->size[0] = b_a->size[0];
			emxEnsureCapacity_creal_T1(b_c, aidx);
			firstRowA = b_a->size[0];
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_c->data[aidx].re = 0.0;
				b_c->data[aidx].im = 0.0;
			}

			if ((b_a->size[0] == 0) || (b_b->size[0] == 0)) {
			}
			else {
				cBegin1 = b_b->size[0] >> 1;
				cEnd1 = (cBegin1 + b_a->size[0]) - 1;
				ma = b_a->size[0];
				if (b_a->size[0] < cBegin1) {
					firstRowB = (cBegin1 - b_a->size[0]) + 1;
				}
				else {
					firstRowB = 0;
				}

				if (b_b->size[0] <= cEnd1) {
					lastRowB = b_b->size[0] - 1;
				}
				else {
					lastRowB = cEnd1;
				}

				iC = 0;
				for (i = firstRowB; i <= lastRowB; i++) {
					if (i < cBegin1) {
						firstRowA = cBegin1 - i;
					}
					else {
						firstRowA = 0;
					}

					if (i + ma <= cEnd1) {
						b_i = ma;
					}
					else {
						b_i = (cEnd1 - i) + 1;
					}

					a_length = b_i - firstRowA;
					cidx = iC;
					for (r = 1; r <= a_length; r++) {
						b_c->data[cidx].re += b_b->data[firstRowB].re * b_a->data[firstRowA];
						b_c->data[cidx].im += b_b->data[firstRowB].im * b_a->data[firstRowA];
						firstRowA++;
						cidx++;
					}

					firstRowB++;
					if (i >= cBegin1) {
						iC++;
					}
				}
			}

			aidx = c->size[0] * c->size[1];
			c->size[0] = 1;
			c->size[1] = b_c->size[0];
			emxEnsureCapacity_creal_T(c, aidx);
			firstRowA = b_c->size[0];
			for (aidx = 0; aidx < firstRowA; aidx++) {
				c->data[c->size[0] * aidx] = b_c->data[aidx];
			}
		}
		else {
			guard1 = true;
		}
	}
	else {
		guard1 = true;
	}

	if (guard1) {
		aidx = c->size[0] * c->size[1];
		c->size[0] = a->size[0];
		c->size[1] = a->size[1];
		emxEnsureCapacity_creal_T(c, aidx);
		firstRowA = a->size[0] * a->size[1];
		for (aidx = 0; aidx < firstRowA; aidx++) {
			c->data[aidx].re = 0.0;
			c->data[aidx].im = 0.0;
		}

		if ((a->size[0] == 0) || (a->size[1] == 0) || ((b->size[0] == 0) || (b->
			size[1] == 0))) {
		}
		else {
			cBegin = b->size[1] >> 1;
			aidx = a->size[1];
			cEnd = (cBegin + aidx) - 1;
			cBegin1 = b->size[0] >> 1;
			firstRowA = a->size[0];
			cEnd1 = cBegin1 + firstRowA;
			ma = a->size[0];
			na = a->size[1] - 1;
			mc = cEnd1 - cBegin1;
			if (a->size[1] < cBegin) {
				firstColB = (cBegin - a->size[1]) + 1;
			}
			else {
				firstColB = 0;
			}

			if (b->size[1] <= cEnd) {
				lastColB = b->size[1] - 1;
			}
			else {
				lastColB = cEnd;
			}

			if (a->size[0] < cBegin1) {
				firstRowB = (cBegin1 - a->size[0]) + 1;
			}
			else {
				firstRowB = 0;
			}

			if (b->size[0] <= cEnd1 - 1) {
				lastRowB = b->size[0];
			}
			else {
				lastRowB = cEnd1;
			}

			while (firstColB <= lastColB) {
				if (firstColB + na < cEnd) {
					lastColA = na;
				}
				else {
					lastColA = cEnd - firstColB;
				}

				if (firstColB < cBegin) {
					k = cBegin - firstColB;
				}
				else {
					k = 0;
				}

				while (k <= lastColA) {
					if (firstColB + k > cBegin) {
						b_firstColB = (firstColB + k) - cBegin;
					}
					else {
						b_firstColB = 0;
					}

					iC = b_firstColB * mc;
					iA = k * ma + 1;
					iB = firstRowB + firstColB * b->size[0];
					for (i = firstRowB; i < lastRowB; i++) {
						if (i < cBegin1) {
							firstRowA = cBegin1 - i;
						}
						else {
							firstRowA = 0;
						}

						if (i + ma <= cEnd1 - 1) {
							c_i = ma;
						}
						else {
							c_i = cEnd1 - i;
						}

						a_length = c_i - firstRowA;
						aidx = (iA + firstRowA) - 1;
						cidx = iC;
						for (r = 1; r <= a_length; r++) {
							c->data[cidx].re += b->data[iB].re * a->data[aidx];
							c->data[cidx].im += b->data[iB].im * a->data[aidx];
							aidx++;
							cidx++;
						}

						iB++;
						if (i >= cBegin1) {
							iC++;
						}
					}

					k++;
				}

				firstColB++;
			}
		}
	}

	emxFree_creal_T(&b_b);
	emxFree_real_T(&b_a);
	emxFree_creal_T(&b_c);
}

//
// Arguments    : emxArray_real_T *x
// Return Type  : void
//
static void b_floor(emxArray_real_T *x)
{
	int nx;
	int k;
	nx = x->size[0] * x->size[1];
	for (k = 0; k < nx; k++) {
		x->data[k] = std::floor(x->data[k]);
	}
}

//
// Arguments    : creal_T x[16384]
// Return Type  : void
//
static void b_ifftshift(creal_T x[16384])
{
	int dim;
	for (dim = 0; dim < 2; dim++) {
		eml_fftshift(x, dim + 1);
	}
}

//
// // Get some necessary variables first
// Arguments    : const creal_T im[9]
//                double ratio
//                emxArray_creal_T *out
// Return Type  : void
//
static void b_interpImg(const creal_T im[9], double ratio, emxArray_creal_T *out)
{
	emxArray_real_T *y;
	double out_rows;
	double out_cols;
	int i1;
	int loop_ub;
	emxArray_real_T *b_y;
	emxArray_real_T *cf;
	emxArray_real_T *rf;
	emxArray_real_T *c;
	emxArray_real_T *r;
	int end;
	int i;
	emxArray_int32_T *r0;
	emxArray_int32_T *r1;
	emxArray_int32_T *r2;
	emxArray_int32_T *r3;
	emxArray_creal_T *r4;
	emxArray_creal_T *r5;
	emxArray_creal_T *r6;
	emxArray_creal_T *r7;
	int i2;
	double re;
	double b_im;
	double b_re;
	double c_im;
	double c_re;
	double d_im;
	emxInit_real_T(&y, 2);
	out_rows = 3.0 * ratio;
	out_cols = 3.0 * ratio;

	//      %// Let S_R = R / R'
	//      S_R = in_rows / out_rows;
	//      %// Let S_C = C / C'
	//      S_C = in_cols / out_cols;
	// // Define grid of co-ordinates in our image
	// // Generate (x,y) pairs for each point in our image
	if (rtIsNaN(out_cols)) {
		i1 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i1);
		y->data[0] = rtNaN;
	}
	else if (out_cols < 1.0) {
		i1 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 0;
		emxEnsureCapacity_real_T(y, i1);
	}
	else if (rtIsInf(out_cols) && (1.0 == out_cols)) {
		i1 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i1);
		y->data[0] = rtNaN;
	}
	else {
		i1 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = (int)std::floor(out_cols - 1.0) + 1;
		emxEnsureCapacity_real_T(y, i1);
		loop_ub = (int)std::floor(out_cols - 1.0);
		for (i1 = 0; i1 <= loop_ub; i1++) {
			y->data[y->size[0] * i1] = 1.0 + (double)i1;
		}
	}

	emxInit_real_T(&b_y, 2);
	if (rtIsNaN(out_rows)) {
		i1 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i1);
		b_y->data[0] = rtNaN;
	}
	else if (out_rows < 1.0) {
		i1 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 0;
		emxEnsureCapacity_real_T(b_y, i1);
	}
	else if (rtIsInf(out_rows) && (1.0 == out_rows)) {
		i1 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i1);
		b_y->data[0] = rtNaN;
	}
	else {
		i1 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = (int)std::floor(out_rows - 1.0) + 1;
		emxEnsureCapacity_real_T(b_y, i1);
		loop_ub = (int)std::floor(out_rows - 1.0);
		for (i1 = 0; i1 <= loop_ub; i1++) {
			b_y->data[b_y->size[0] * i1] = 1.0 + (double)i1;
		}
	}

	emxInit_real_T(&cf, 2);
	emxInit_real_T(&rf, 2);
	meshgrid(y, b_y, cf, rf);

	// // Let r_f = r'*S_R for r = 1,...,R'
	// // Let c_f = c'*S_C for c = 1,...,C'
	loop_ub = cf->size[0] * cf->size[1] - 1;
	i1 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i1);
	emxFree_real_T(&b_y);
	emxFree_real_T(&y);
	for (i1 = 0; i1 <= loop_ub; i1++) {
		cf->data[i1] /= ratio;
	}

	loop_ub = rf->size[0] * rf->size[1] - 1;
	i1 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i1);
	for (i1 = 0; i1 <= loop_ub; i1++) {
		rf->data[i1] /= ratio;
	}

	emxInit_real_T(&c, 2);

	// // Let r = floor(rf) and c = floor(cf)
	i1 = c->size[0] * c->size[1];
	c->size[0] = cf->size[0];
	c->size[1] = cf->size[1];
	emxEnsureCapacity_real_T(c, i1);
	loop_ub = cf->size[0] * cf->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		c->data[i1] = cf->data[i1];
	}

	emxInit_real_T(&r, 2);
	b_floor(c);
	i1 = r->size[0] * r->size[1];
	r->size[0] = rf->size[0];
	r->size[1] = rf->size[1];
	emxEnsureCapacity_real_T(r, i1);
	loop_ub = rf->size[0] * rf->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		r->data[i1] = rf->data[i1];
	}

	b_floor(r);

	// // Any values out of range, cap
	end = r->size[0] * r->size[1] - 1;
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			loop_ub++;
		}
	}

	emxInit_int32_T(&r0, 1);
	i1 = r0->size[0];
	r0->size[0] = loop_ub;
	emxEnsureCapacity_int32_T(r0, i1);
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			r0->data[loop_ub] = i + 1;
			loop_ub++;
		}
	}

	loop_ub = r0->size[0] - 1;
	for (i1 = 0; i1 <= loop_ub; i1++) {
		r->data[r0->data[i1] - 1] = 1.0;
	}

	emxFree_int32_T(&r0);
	end = c->size[0] * c->size[1] - 1;
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			loop_ub++;
		}
	}

	emxInit_int32_T(&r1, 1);
	i1 = r1->size[0];
	r1->size[0] = loop_ub;
	emxEnsureCapacity_int32_T(r1, i1);
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			r1->data[loop_ub] = i + 1;
			loop_ub++;
		}
	}

	loop_ub = r1->size[0] - 1;
	for (i1 = 0; i1 <= loop_ub; i1++) {
		c->data[r1->data[i1] - 1] = 1.0;
	}

	emxFree_int32_T(&r1);
	end = r->size[0] * r->size[1] - 1;
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > 2.0) {
			loop_ub++;
		}
	}

	emxInit_int32_T(&r2, 1);
	i1 = r2->size[0];
	r2->size[0] = loop_ub;
	emxEnsureCapacity_int32_T(r2, i1);
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > 2.0) {
			r2->data[loop_ub] = i + 1;
			loop_ub++;
		}
	}

	loop_ub = r2->size[0] - 1;
	for (i1 = 0; i1 <= loop_ub; i1++) {
		r->data[r2->data[i1] - 1] = 2.0;
	}

	emxFree_int32_T(&r2);
	end = c->size[0] * c->size[1] - 1;
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > 2.0) {
			loop_ub++;
		}
	}

	emxInit_int32_T(&r3, 1);
	i1 = r3->size[0];
	r3->size[0] = loop_ub;
	emxEnsureCapacity_int32_T(r3, i1);
	loop_ub = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > 2.0) {
			r3->data[loop_ub] = i + 1;
			loop_ub++;
		}
	}

	loop_ub = r3->size[0] - 1;
	for (i1 = 0; i1 <= loop_ub; i1++) {
		c->data[r3->data[i1] - 1] = 2.0;
	}

	emxFree_int32_T(&r3);

	// // Let delta_R = rf - r and delta_C = cf - c
	loop_ub = rf->size[0] * rf->size[1] - 1;
	i1 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i1);
	for (i1 = 0; i1 <= loop_ub; i1++) {
		rf->data[i1] -= r->data[i1];
	}

	loop_ub = cf->size[0] * cf->size[1] - 1;
	i1 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i1);
	for (i1 = 0; i1 <= loop_ub; i1++) {
		cf->data[i1] -= c->data[i1];
	}

	// // Final line of algorithm
	// // Get column major indices for each point we wish
	// // to access
	// // Now interpolate
	// // Create output matrix that is the same class as input
	//      out = cast(out, class(im));
	i1 = out->size[0] * out->size[1];
	out->size[0] = (int)out_rows;
	out->size[1] = (int)out_cols;
	emxEnsureCapacity_creal_T(out, i1);
	loop_ub = (int)out_rows * (int)out_cols;
	for (i1 = 0; i1 < loop_ub; i1++) {
		out->data[i1].re = 0.0;
		out->data[i1].im = 0.0;
	}

	emxInit_creal_T(&r4, 2);

	// // Get i'th channel
	// // Interpolate the channel
	i1 = r4->size[0] * r4->size[1];
	r4->size[0] = r->size[0];
	r4->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r4, i1);
	loop_ub = r->size[0] * r->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		r4->data[i1] = im[((int)r->data[i1] + 3 * ((int)c->data[i1] - 1)) - 1];
	}

	emxInit_creal_T(&r5, 2);
	i1 = r5->size[0] * r5->size[1];
	r5->size[0] = r->size[0];
	r5->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r5, i1);
	loop_ub = r->size[0] * r->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		r5->data[i1] = im[((int)(r->data[i1] + 1.0) + 3 * ((int)c->data[i1] - 1)) -
			1];
	}

	emxInit_creal_T(&r6, 2);
	i1 = r6->size[0] * r6->size[1];
	r6->size[0] = r->size[0];
	r6->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r6, i1);
	loop_ub = r->size[0] * r->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		r6->data[i1] = im[((int)r->data[i1] + 3 * ((int)(c->data[i1] + 1.0) - 1)) -
			1];
	}

	emxInit_creal_T(&r7, 2);
	i1 = r7->size[0] * r7->size[1];
	r7->size[0] = r->size[0];
	r7->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r7, i1);
	loop_ub = r->size[0] * r->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		r7->data[i1] = im[((int)(r->data[i1] + 1.0) + 3 * ((int)(c->data[i1] + 1.0)
			- 1)) - 1];
	}

	emxFree_real_T(&r);
	emxFree_real_T(&c);
	i = out->size[0];
	loop_ub = r4->size[1];
	for (i1 = 0; i1 < loop_ub; i1++) {
		end = r4->size[0];
		for (i2 = 0; i2 < end; i2++) {
			out_rows = (1.0 - rf->data[i2 + rf->size[0] * i1]) * r4->data[i2 +
				r4->size[0] * i1].re;
			out_cols = (1.0 - rf->data[i2 + rf->size[0] * i1]) * r4->data[i2 +
				r4->size[0] * i1].im;
			re = rf->data[i2 + rf->size[0] * i1] * r5->data[i2 + r5->size[0] * i1].re;
			b_im = rf->data[i2 + rf->size[0] * i1] * r5->data[i2 + r5->size[0] * i1].
				im;
			b_re = (1.0 - rf->data[i2 + rf->size[0] * i1]) * r6->data[i2 + r6->size[0]
				* i1].re;
			c_im = (1.0 - rf->data[i2 + rf->size[0] * i1]) * r6->data[i2 + r6->size[0]
				* i1].im;
			c_re = rf->data[i2 + rf->size[0] * i1] * r7->data[i2 + r7->size[0] * i1].
				re;
			d_im = rf->data[i2 + rf->size[0] * i1] * r7->data[i2 + r7->size[0] * i1].
				im;
			out->data[i2 + i * i1].re = ((out_rows * (1.0 - cf->data[i2 + cf->size[0] *
				i1]) + re * (1.0 - cf->data[i2 + cf->size[0] * i1])) + b_re * cf->
				data[i2 + cf->size[0] * i1]) + c_re * cf->data[i2 + cf->size[0] * i1];
			out->data[i2 + i * i1].im = ((out_cols * (1.0 - cf->data[i2 + cf->size[0] *
				i1]) + b_im * (1.0 - cf->data[i2 + cf->size[0] * i1])) + c_im * cf->
				data[i2 + cf->size[0] * i1]) + d_im * cf->data[i2 + cf->size[0] * i1];
		}
	}

	emxFree_creal_T(&r7);
	emxFree_creal_T(&r6);
	emxFree_creal_T(&r5);
	emxFree_creal_T(&r4);
	emxFree_real_T(&rf);
	emxFree_real_T(&cf);
}

//
// Arguments    : double x
//                double y
// Return Type  : double
//
static double b_mod(double x, double y)
{
	double r;
	boolean_T rEQ0;
	double q;
	r = x;
	if ((!rtIsInf(x)) && (!rtIsNaN(x)) && ((!rtIsInf(y)) && (!rtIsNaN(y)))) {
		if (x == 0.0) {
			r = y * 0.0;
		}
		else {
			if (y != 0.0) {
				r = std::fmod(x, y);
				rEQ0 = (r == 0.0);
				if ((!rEQ0) && (y > std::floor(y))) {
					q = std::abs(x / y);
					rEQ0 = (std::abs(q - std::floor(q + 0.5)) <= 2.2204460492503131E-16 *
						q);
				}

				if (rEQ0) {
					r = y * 0.0;
				}
				else {
					if ((x < 0.0) != (y < 0.0)) {
						r += y;
					}
				}
			}
		}
	}
	else {
		if (y != 0.0) {
			r = rtNaN;
		}
	}

	return r;
}

//
// Arguments    : const creal_T x[16384]
//                const double costab[65]
//                const double sintab[65]
//                creal_T y[16384]
// Return Type  : void
//
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384])
{
	int k;
	creal_T rwork[128];
	int xoff;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff)

	for (k = 1; k < 129; k++) {
		xoff = (k - 1) << 7;
		r2br_r2dit_trig_impl(x, xoff, costab, sintab, rwork);
		memcpy(&y[(k << 7) + -128], &rwork[0], sizeof(creal_T) << 7);
	}
}

//
// Arguments    : const emxArray_real_T *Obj
//                double r1
//                double r2
//                double c1
//                double c2
//                emxArray_real_T *f
// Return Type  : void
//
static void b_zone(const emxArray_real_T *Obj, double r1, double r2, double c1,
	double c2, emxArray_real_T *f)
{
	int i;
	int j;
	i = f->size[0] * f->size[1];
	f->size[0] = Obj->size[0];
	f->size[1] = Obj->size[1];
	emxEnsureCapacity_real_T(f, i);
	for (i = 0; i < Obj->size[0]; i++) {
		for (j = 0; j < Obj->size[1]; j++) {
			if ((1.0 + (double)i >= r1) && (1.0 + (double)i <= r2) && (1.0 + (double)j
				>= c1) && (1.0 + (double)j <= c2)) {
				f->data[i + f->size[0] * j] = Obj->data[i + Obj->size[0] * j];
			}
			else {
				f->data[i + f->size[0] * j] = 0.0;
			}
		}
	}
}

//
// // Get some necessary variables first
// Arguments    : const emxArray_creal_T *im
//                double ratio
//                emxArray_creal_T *out
// Return Type  : void
//
static void c_interpImg(const emxArray_creal_T *im, double ratio,
	emxArray_creal_T *out)
{
	emxArray_real_T *y;
	int in_cols;
	int in_rows;
	double out_rows;
	double out_cols;
	int i7;
	int loop_ub;
	emxArray_real_T *b_y;
	emxArray_real_T *cf;
	emxArray_real_T *rf;
	emxArray_real_T *c;
	emxArray_real_T *r;
	int end;
	int trueCount;
	int i;
	emxArray_int32_T *r8;
	emxArray_int32_T *r9;
	emxArray_int32_T *r10;
	emxArray_int32_T *r11;
	emxArray_creal_T *chan;
	int b_loop_ub;
	emxArray_creal_T *r12;
	int i8;
	emxArray_creal_T *r13;
	emxArray_creal_T *r14;
	emxArray_creal_T *r15;
	double re;
	double b_im;
	double b_re;
	double c_im;
	double c_re;
	double d_im;
	emxInit_real_T(&y, 2);
	in_cols = im->size[1];
	in_rows = im->size[0];
	out_rows = (double)im->size[0] * ratio;
	out_cols = (double)im->size[1] * ratio;

	//      %// Let S_R = R / R'
	//      S_R = in_rows / out_rows;
	//      %// Let S_C = C / C'
	//      S_C = in_cols / out_cols;
	// // Define grid of co-ordinates in our image
	// // Generate (x,y) pairs for each point in our image
	if (rtIsNaN(out_cols)) {
		i7 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i7);
		y->data[0] = rtNaN;
	}
	else if (out_cols < 1.0) {
		i7 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 0;
		emxEnsureCapacity_real_T(y, i7);
	}
	else if (rtIsInf(out_cols) && (1.0 == out_cols)) {
		i7 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i7);
		y->data[0] = rtNaN;
	}
	else {
		i7 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = (int)std::floor(out_cols - 1.0) + 1;
		emxEnsureCapacity_real_T(y, i7);
		loop_ub = (int)std::floor(out_cols - 1.0);
		for (i7 = 0; i7 <= loop_ub; i7++) {
			y->data[y->size[0] * i7] = 1.0 + (double)i7;
		}
	}

	emxInit_real_T(&b_y, 2);
	if (rtIsNaN(out_rows)) {
		i7 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i7);
		b_y->data[0] = rtNaN;
	}
	else if (out_rows < 1.0) {
		i7 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 0;
		emxEnsureCapacity_real_T(b_y, i7);
	}
	else if (rtIsInf(out_rows) && (1.0 == out_rows)) {
		i7 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i7);
		b_y->data[0] = rtNaN;
	}
	else {
		i7 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = (int)std::floor(out_rows - 1.0) + 1;
		emxEnsureCapacity_real_T(b_y, i7);
		loop_ub = (int)std::floor(out_rows - 1.0);
		for (i7 = 0; i7 <= loop_ub; i7++) {
			b_y->data[b_y->size[0] * i7] = 1.0 + (double)i7;
		}
	}

	emxInit_real_T(&cf, 2);
	emxInit_real_T(&rf, 2);
	meshgrid(y, b_y, cf, rf);

	// // Let r_f = r'*S_R for r = 1,...,R'
	// // Let c_f = c'*S_C for c = 1,...,C'
	loop_ub = cf->size[0] * cf->size[1] - 1;
	i7 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i7);
	emxFree_real_T(&b_y);
	emxFree_real_T(&y);
	for (i7 = 0; i7 <= loop_ub; i7++) {
		cf->data[i7] /= ratio;
	}

	loop_ub = rf->size[0] * rf->size[1] - 1;
	i7 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i7);
	for (i7 = 0; i7 <= loop_ub; i7++) {
		rf->data[i7] /= ratio;
	}

	emxInit_real_T(&c, 2);

	// // Let r = floor(rf) and c = floor(cf)
	i7 = c->size[0] * c->size[1];
	c->size[0] = cf->size[0];
	c->size[1] = cf->size[1];
	emxEnsureCapacity_real_T(c, i7);
	loop_ub = cf->size[0] * cf->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		c->data[i7] = cf->data[i7];
	}

	emxInit_real_T(&r, 2);
	b_floor(c);
	i7 = r->size[0] * r->size[1];
	r->size[0] = rf->size[0];
	r->size[1] = rf->size[1];
	emxEnsureCapacity_real_T(r, i7);
	loop_ub = rf->size[0] * rf->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		r->data[i7] = rf->data[i7];
	}

	b_floor(r);

	// // Any values out of range, cap
	end = r->size[0] * r->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r8, 1);
	i7 = r8->size[0];
	r8->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r8, i7);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			r8->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r8->size[0] - 1;
	for (i7 = 0; i7 <= loop_ub; i7++) {
		r->data[r8->data[i7] - 1] = 1.0;
	}

	emxFree_int32_T(&r8);
	end = c->size[0] * c->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r9, 1);
	i7 = r9->size[0];
	r9->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r9, i7);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			r9->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r9->size[0] - 1;
	for (i7 = 0; i7 <= loop_ub; i7++) {
		c->data[r9->data[i7] - 1] = 1.0;
	}

	emxFree_int32_T(&r9);
	end = r->size[0] * r->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > (double)in_rows - 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r10, 1);
	i7 = r10->size[0];
	r10->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r10, i7);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > (double)in_rows - 1.0) {
			r10->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r10->size[0] - 1;
	for (i7 = 0; i7 <= loop_ub; i7++) {
		r->data[r10->data[i7] - 1] = im->size[0] - 1;
	}

	emxFree_int32_T(&r10);
	end = c->size[0] * c->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > (double)in_cols - 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r11, 1);
	i7 = r11->size[0];
	r11->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r11, i7);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > (double)in_cols - 1.0) {
			r11->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r11->size[0] - 1;
	for (i7 = 0; i7 <= loop_ub; i7++) {
		c->data[r11->data[i7] - 1] = im->size[1] - 1;
	}

	emxFree_int32_T(&r11);

	// // Let delta_R = rf - r and delta_C = cf - c
	loop_ub = rf->size[0] * rf->size[1] - 1;
	i7 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i7);
	for (i7 = 0; i7 <= loop_ub; i7++) {
		rf->data[i7] -= r->data[i7];
	}

	loop_ub = cf->size[0] * cf->size[1] - 1;
	i7 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i7);
	for (i7 = 0; i7 <= loop_ub; i7++) {
		cf->data[i7] -= c->data[i7];
	}

	// // Final line of algorithm
	// // Get column major indices for each point we wish
	// // to access
	trueCount = im->size[0];
	i = im->size[0];
	end = im->size[0];
	in_cols = im->size[0];

	// // Now interpolate
	// // Create output matrix that is the same class as input
	//      out = cast(out, class(im));
	i7 = out->size[0] * out->size[1];
	out->size[0] = (int)out_rows;
	out->size[1] = (int)out_cols;
	emxEnsureCapacity_creal_T(out, i7);
	loop_ub = (int)out_rows * (int)out_cols;
	for (i7 = 0; i7 < loop_ub; i7++) {
		out->data[i7].re = 0.0;
		out->data[i7].im = 0.0;
	}

	emxInit_creal_T(&chan, 2);
	in_rows = im->size[0];
	loop_ub = im->size[0];
	b_loop_ub = im->size[1];
	i7 = chan->size[0] * chan->size[1];
	chan->size[0] = loop_ub;
	chan->size[1] = b_loop_ub;
	emxEnsureCapacity_creal_T(chan, i7);
	for (i7 = 0; i7 < b_loop_ub; i7++) {
		for (i8 = 0; i8 < loop_ub; i8++) {
			chan->data[i8 + chan->size[0] * i7] = im->data[i8 + in_rows * i7];
		}
	}

	emxInit_creal_T(&r12, 2);

	// // Get i'th channel
	// // Interpolate the channel
	i7 = r12->size[0] * r12->size[1];
	r12->size[0] = r->size[0];
	r12->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r12, i7);
	loop_ub = r->size[0] * r->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		r12->data[i7] = chan->data[((int)r->data[i7] + trueCount * ((int)c->data[i7]
			- 1)) - 1];
	}

	emxInit_creal_T(&r13, 2);
	i7 = r13->size[0] * r13->size[1];
	r13->size[0] = r->size[0];
	r13->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r13, i7);
	loop_ub = r->size[0] * r->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		r13->data[i7] = chan->data[((int)(r->data[i7] + 1.0) + i * ((int)c->data[i7]
			- 1)) - 1];
	}

	emxInit_creal_T(&r14, 2);
	i7 = r14->size[0] * r14->size[1];
	r14->size[0] = r->size[0];
	r14->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r14, i7);
	loop_ub = r->size[0] * r->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		r14->data[i7] = chan->data[((int)r->data[i7] + end * ((int)(c->data[i7] +
			1.0) - 1)) - 1];
	}

	emxInit_creal_T(&r15, 2);
	i7 = r15->size[0] * r15->size[1];
	r15->size[0] = r->size[0];
	r15->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r15, i7);
	loop_ub = r->size[0] * r->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		r15->data[i7] = chan->data[((int)(r->data[i7] + 1.0) + in_cols * ((int)
			(c->data[i7] + 1.0) - 1)) - 1];
	}

	emxFree_creal_T(&chan);
	emxFree_real_T(&r);
	emxFree_real_T(&c);
	trueCount = out->size[0];
	loop_ub = r12->size[1];
	for (i7 = 0; i7 < loop_ub; i7++) {
		b_loop_ub = r12->size[0];
		for (i8 = 0; i8 < b_loop_ub; i8++) {
			out_rows = (1.0 - rf->data[i8 + rf->size[0] * i7]) * r12->data[i8 +
				r12->size[0] * i7].re;
			out_cols = (1.0 - rf->data[i8 + rf->size[0] * i7]) * r12->data[i8 +
				r12->size[0] * i7].im;
			re = rf->data[i8 + rf->size[0] * i7] * r13->data[i8 + r13->size[0] * i7].
				re;
			b_im = rf->data[i8 + rf->size[0] * i7] * r13->data[i8 + r13->size[0] * i7]
				.im;
			b_re = (1.0 - rf->data[i8 + rf->size[0] * i7]) * r14->data[i8 + r14->size
				[0] * i7].re;
			c_im = (1.0 - rf->data[i8 + rf->size[0] * i7]) * r14->data[i8 + r14->size
				[0] * i7].im;
			c_re = rf->data[i8 + rf->size[0] * i7] * r15->data[i8 + r15->size[0] * i7]
				.re;
			d_im = rf->data[i8 + rf->size[0] * i7] * r15->data[i8 + r15->size[0] * i7]
				.im;
			out->data[i8 + trueCount * i7].re = ((out_rows * (1.0 - cf->data[i8 +
				cf->size[0] * i7]) + re * (1.0 - cf->data[i8 + cf->size[0] * i7])) +
				b_re * cf->data[i8 + cf->size[0] * i7]) + c_re * cf->data[i8 + cf->size
				[0] * i7];
			out->data[i8 + trueCount * i7].im = ((out_cols * (1.0 - cf->data[i8 +
				cf->size[0] * i7]) + b_im * (1.0 - cf->data[i8 + cf->size[0] * i7])) +
				c_im * cf->data[i8 + cf->size[0] * i7]) + d_im * cf->data[i8 + cf->size
				[0] * i7];
		}
	}

	emxFree_creal_T(&r15);
	emxFree_creal_T(&r14);
	emxFree_creal_T(&r13);
	emxFree_creal_T(&r12);
	emxFree_real_T(&rf);
	emxFree_real_T(&cf);
}

//
// Arguments    : const creal_T x[16384]
//                const double costab[65]
//                const double sintab[65]
//                creal_T y[16384]
// Return Type  : void
//
static void c_r2br_r2dit_trig(const creal_T x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384])
{
	int k;
	int i4;
	creal_T rwork[128];
	int xoff;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff)

	for (k = 1; k < 129; k++) {
		xoff = (k - 1) << 7;
		r2br_r2dit_trig_impl(x, xoff, costab, sintab, rwork);
		memcpy(&y[(k << 7) + -128], &rwork[0], sizeof(creal_T) << 7);
	}

	for (i4 = 0; i4 < 16384; i4++) {
		y[i4].re *= 0.0078125;
		y[i4].im *= 0.0078125;
	}
}

//
// Arguments    : const emxArray_real_T *a
//                const emxArray_real_T *b
//                emxArray_real_T *c
// Return Type  : void
//
static void conv2(const emxArray_real_T *a, const emxArray_real_T *b,
	emxArray_real_T *c)
{
	boolean_T p;
	emxArray_real_T *b_c;
	emxArray_real_T *b_a;
	emxArray_real_T *b_b;
	boolean_T guard1 = false;
	int firstRowA;
	int aidx;
	int cBegin;
	int cEnd;
	int cBegin1;
	int cEnd1;
	int ma;
	int na;
	int mc;
	int firstColB;
	int lastColB;
	int firstRowB;
	int lastRowB;
	int iC;
	int i;
	int lastColA;
	int k;
	int b_i;
	int a_length;
	int cidx;
	int r;
	int b_firstColB;
	int iA;
	int iB;
	int c_i;
	p = (a->size[0] == 1);
	emxInit_real_T1(&b_c, 1);
	emxInit_real_T1(&b_a, 1);
	emxInit_real_T1(&b_b, 1);
	guard1 = false;
	if (p) {
		p = (b->size[0] == 1);
		if (p) {
			firstRowA = a->size[1];
			aidx = b_a->size[0];
			b_a->size[0] = firstRowA;
			emxEnsureCapacity_real_T1(b_a, aidx);
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_a->data[aidx] = a->data[a->size[0] * aidx];
			}

			firstRowA = b->size[1];
			aidx = b_b->size[0];
			b_b->size[0] = firstRowA;
			emxEnsureCapacity_real_T1(b_b, aidx);
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_b->data[aidx] = b->data[b->size[0] * aidx];
			}

			aidx = b_c->size[0];
			b_c->size[0] = b_a->size[0];
			emxEnsureCapacity_real_T1(b_c, aidx);
			firstRowA = b_a->size[0];
			for (aidx = 0; aidx < firstRowA; aidx++) {
				b_c->data[aidx] = 0.0;
			}

			if ((b_a->size[0] == 0) || (b_b->size[0] == 0)) {
			}
			else {
				cBegin1 = b_b->size[0] >> 1;
				cEnd1 = (cBegin1 + b_a->size[0]) - 1;
				ma = b_a->size[0];
				if (b_a->size[0] < cBegin1) {
					firstRowB = (cBegin1 - b_a->size[0]) + 1;
				}
				else {
					firstRowB = 0;
				}

				if (b_b->size[0] <= cEnd1) {
					lastRowB = b_b->size[0] - 1;
				}
				else {
					lastRowB = cEnd1;
				}

				iC = 0;
				for (i = firstRowB; i <= lastRowB; i++) {
					if (i < cBegin1) {
						firstRowA = cBegin1 - i;
					}
					else {
						firstRowA = 0;
					}

					if (i + ma <= cEnd1) {
						b_i = ma;
					}
					else {
						b_i = (cEnd1 - i) + 1;
					}

					a_length = b_i - firstRowA;
					cidx = iC;
					for (r = 1; r <= a_length; r++) {
						b_c->data[cidx] += b_b->data[firstRowB] * b_a->data[firstRowA];
						firstRowA++;
						cidx++;
					}

					firstRowB++;
					if (i >= cBegin1) {
						iC++;
					}
				}
			}

			aidx = c->size[0] * c->size[1];
			c->size[0] = 1;
			c->size[1] = b_c->size[0];
			emxEnsureCapacity_real_T(c, aidx);
			firstRowA = b_c->size[0];
			for (aidx = 0; aidx < firstRowA; aidx++) {
				c->data[c->size[0] * aidx] = b_c->data[aidx];
			}
		}
		else {
			guard1 = true;
		}
	}
	else {
		guard1 = true;
	}

	if (guard1) {
		aidx = c->size[0] * c->size[1];
		c->size[0] = a->size[0];
		c->size[1] = a->size[1];
		emxEnsureCapacity_real_T(c, aidx);
		firstRowA = a->size[0] * a->size[1];
		for (aidx = 0; aidx < firstRowA; aidx++) {
			c->data[aidx] = 0.0;
		}

		if ((a->size[0] == 0) || (a->size[1] == 0) || ((b->size[0] == 0) || (b->
			size[1] == 0))) {
		}
		else {
			cBegin = b->size[1] >> 1;
			aidx = a->size[1];
			cEnd = (cBegin + aidx) - 1;
			cBegin1 = b->size[0] >> 1;
			firstRowA = a->size[0];
			cEnd1 = cBegin1 + firstRowA;
			ma = a->size[0];
			na = a->size[1] - 1;
			mc = cEnd1 - cBegin1;
			if (a->size[1] < cBegin) {
				firstColB = (cBegin - a->size[1]) + 1;
			}
			else {
				firstColB = 0;
			}

			if (b->size[1] <= cEnd) {
				lastColB = b->size[1] - 1;
			}
			else {
				lastColB = cEnd;
			}

			if (a->size[0] < cBegin1) {
				firstRowB = (cBegin1 - a->size[0]) + 1;
			}
			else {
				firstRowB = 0;
			}

			if (b->size[0] <= cEnd1 - 1) {
				lastRowB = b->size[0];
			}
			else {
				lastRowB = cEnd1;
			}

			while (firstColB <= lastColB) {
				if (firstColB + na < cEnd) {
					lastColA = na;
				}
				else {
					lastColA = cEnd - firstColB;
				}

				if (firstColB < cBegin) {
					k = cBegin - firstColB;
				}
				else {
					k = 0;
				}

				while (k <= lastColA) {
					if (firstColB + k > cBegin) {
						b_firstColB = (firstColB + k) - cBegin;
					}
					else {
						b_firstColB = 0;
					}

					iC = b_firstColB * mc;
					iA = k * ma;
					iB = firstRowB + firstColB * b->size[0];
					for (i = firstRowB; i < lastRowB; i++) {
						if (i < cBegin1) {
							firstRowA = cBegin1 - i;
						}
						else {
							firstRowA = 0;
						}

						if (i + ma <= cEnd1 - 1) {
							c_i = ma;
						}
						else {
							c_i = cEnd1 - i;
						}

						a_length = c_i - firstRowA;
						aidx = iA + firstRowA;
						cidx = iC;
						for (r = 1; r <= a_length; r++) {
							c->data[cidx] += b->data[iB] * a->data[aidx];
							aidx++;
							cidx++;
						}

						iB++;
						if (i >= cBegin1) {
							iC++;
						}
					}

					k++;
				}

				firstColB++;
			}
		}
	}

	emxFree_real_T(&b_b);
	emxFree_real_T(&b_a);
	emxFree_real_T(&b_c);
}

//
// Arguments    : creal_T x[16384]
//                int dim
// Return Type  : void
//
static void eml_fftshift(creal_T x[16384], int dim)
{
	int vstride;
	int k;
	int npages;
	int b_k;
	int vspread;
	int midoffset;
	int i2;
	int i;
	int i1;
	int j;
	int ia;
	int ib;
	double xtmp_re;
	double xtmp_im;
	if (!(dim > 2)) {
		vstride = 1;
		for (k = 1; k < dim; k++) {
			if (k <= 2) {
				b_k = 128;
			}
			else {
				b_k = 1;
			}

			vstride *= b_k;
		}

		npages = 1;
		for (k = dim + 1; k < 3; k++) {
			npages <<= 7;
		}

		vspread = 127 * vstride;
		midoffset = (vstride << 6) - 1;
		i2 = 0;
		for (i = 1; i <= npages; i++) {
			i1 = i2;
			i2 += vspread;
			for (j = 1; j <= vstride; j++) {
				i1++;
				i2++;
				ia = i1 - 1;
				ib = i1 + midoffset;
				for (k = 0; k < 64; k++) {
					xtmp_re = x[ia].re;
					xtmp_im = x[ia].im;
					x[ia] = x[ib];
					x[ib].re = xtmp_re;
					x[ib].im = xtmp_im;
					ia += vstride;
					ib += vstride;
				}
			}
		}
	}
}

//
// Arguments    : double x[16384]
//                int dim
// Return Type  : void
//
static void eml_ifftshift(double x[16384], int dim)
{
	int vstride;
	int k;
	int npages;
	int b_k;
	int vspread;
	int midoffset;
	int i2;
	int i;
	int i1;
	int j;
	int ia;
	int ib;
	double tmp;
	if (!(dim > 2)) {
		vstride = 1;
		for (k = 1; k < dim; k++) {
			if (k <= 2) {
				b_k = 128;
			}
			else {
				b_k = 1;
			}

			vstride *= b_k;
		}

		npages = 1;
		for (k = dim + 1; k < 3; k++) {
			npages <<= 7;
		}

		vspread = 127 * vstride;
		midoffset = (vstride << 6) - 1;
		i2 = 0;
		for (i = 1; i <= npages; i++) {
			i1 = i2;
			i2 += vspread;
			for (j = 1; j <= vstride; j++) {
				i1++;
				i2++;
				ia = i1 - 1;
				ib = i1 + midoffset;
				for (k = 0; k < 64; k++) {
					tmp = x[ia];
					x[ia] = x[ib];
					x[ib] = tmp;
					ia += vstride;
					ib += vstride;
				}
			}
		}
	}
}

//
// Arguments    : double x[16384]
// Return Type  : void
//
static void ifftshift(double x[16384])
{
	int dim;
	for (dim = 0; dim < 2; dim++) {
		eml_ifftshift(x, dim + 1);
	}
}

//
// Arguments    : const emxArray_real_T *x
//                const emxArray_real_T *y
//                emxArray_real_T *xx
//                emxArray_real_T *yy
// Return Type  : void
//
static void meshgrid(const emxArray_real_T *x, const emxArray_real_T *y,
	emxArray_real_T *xx, emxArray_real_T *yy)
{
	int unnamed_idx_0;
	int unnamed_idx_1;
	int i3;
	unnamed_idx_0 = y->size[1];
	unnamed_idx_1 = x->size[1];
	i3 = xx->size[0] * xx->size[1];
	xx->size[0] = unnamed_idx_0;
	xx->size[1] = unnamed_idx_1;
	emxEnsureCapacity_real_T(xx, i3);
	unnamed_idx_0 = y->size[1];
	unnamed_idx_1 = x->size[1];
	i3 = yy->size[0] * yy->size[1];
	yy->size[0] = unnamed_idx_0;
	yy->size[1] = unnamed_idx_1;
	emxEnsureCapacity_real_T(yy, i3);
	if ((x->size[1] == 0) || (y->size[1] == 0)) {
	}
	else {
		for (unnamed_idx_0 = 0; unnamed_idx_0 < x->size[1]; unnamed_idx_0++) {
			for (unnamed_idx_1 = 0; unnamed_idx_1 < y->size[1]; unnamed_idx_1++) {
				xx->data[unnamed_idx_1 + xx->size[0] * unnamed_idx_0] = x->
					data[unnamed_idx_0];
				yy->data[unnamed_idx_1 + yy->size[0] * unnamed_idx_0] = y->
					data[unnamed_idx_1];
			}
		}
	}
}

//
// Arguments    : const creal_T varargin_1[16384]
//                const double varargin_2[2]
//                emxArray_creal_T *b
// Return Type  : void
//
static void padarray(const creal_T varargin_1[16384], const double varargin_2[2],
	emxArray_creal_T *b)
{
	int i5;
	double dv3[2];
	int j;
	int i;
	int i6;
	for (i5 = 0; i5 < 2; i5++) {
		dv3[i5] = 128.0 + 2.0 * varargin_2[i5];
	}

	i5 = b->size[0] * b->size[1];
	b->size[0] = (int)dv3[0];
	b->size[1] = (int)dv3[1];
	emxEnsureCapacity_creal_T(b, i5);
	for (j = 0; j < (int)varargin_2[1]; j++) {
		i5 = b->size[0];
		for (i = 0; i < i5; i++) {
			b->data[i + b->size[0] * j].re = 0.0;
			b->data[i + b->size[0] * j].im = 0.0;
		}
	}

	i5 = b->size[1];
	for (j = (int)varargin_2[1] + 128; j < i5; j++) {
		i6 = b->size[0];
		for (i = 0; i < i6; i++) {
			b->data[i + b->size[0] * j].re = 0.0;
			b->data[i + b->size[0] * j].im = 0.0;
		}
	}

	for (j = 0; j < 128; j++) {
		for (i = 0; i < (int)varargin_2[0]; i++) {
			b->data[i + b->size[0] * (j + (int)varargin_2[1])].re = 0.0;
			b->data[i + b->size[0] * (j + (int)varargin_2[1])].im = 0.0;
		}
	}

	for (j = 0; j < 128; j++) {
		i5 = b->size[0];
		for (i = (int)varargin_2[0] + 128; i < i5; i++) {
			b->data[i + b->size[0] * (j + (int)varargin_2[1])].re = 0.0;
			b->data[i + b->size[0] * (j + (int)varargin_2[1])].im = 0.0;
		}
	}

	for (j = 0; j < 128; j++) {
		for (i = 0; i < 128; i++) {
			int k = i + (j << 7);
			b->data[(i + (int)varargin_2[0]) + b->size[0] * (j + (int)varargin_2[1])] =
				varargin_1[i + (j << 7)];
		}
	}
}

//
// Arguments    : const double x[16384]
//                const double costab[65]
//                const double sintab[65]
//                creal_T y[16384]
// Return Type  : void
//
static void r2br_r2dit_trig(const double x[16384], const double costab[65],
	const double sintab[65], creal_T y[16384])
{
	int k;
	creal_T rwork[128];
	int xoff;
	int ju;
	int iy;
	int i;
	boolean_T tst;
	double temp_re;
	double temp_im;
	int iheight;
	int istart;
	int j;
	double twid_re;
	double twid_im;
	int ihi;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff,ju,iy,i,tst,temp_re,temp_im,iheight,istart,j,twid_re,twid_im,ihi)

	for (k = 1; k < 129; k++) {
		xoff = (k - 1) << 7;
		ju = 0;
		iy = 0;
		for (i = 0; i < 127; i++) {
			rwork[iy].re = x[xoff];
			rwork[iy].im = 0.0;
			iy = 128;
			tst = true;
			while (tst) {
				iy >>= 1;
				ju ^= iy;
				tst = ((ju & iy) == 0);
			}

			iy = ju;
			xoff++;
		}

		rwork[iy].re = x[xoff];
		rwork[iy].im = 0.0;
		for (i = 0; i <= 127; i += 2) {
			temp_re = rwork[i + 1].re;
			temp_im = rwork[i + 1].im;
			rwork[i + 1].re = rwork[i].re - rwork[i + 1].re;
			rwork[i + 1].im = rwork[i].im - rwork[i + 1].im;
			rwork[i].re += temp_re;
			rwork[i].im += temp_im;
		}

		iy = 2;
		xoff = 4;
		ju = 32;
		iheight = 125;
		while (ju > 0) {
			for (i = 0; i < iheight; i += xoff) {
				temp_re = rwork[i + iy].re;
				temp_im = rwork[i + iy].im;
				rwork[i + iy].re = rwork[i].re - temp_re;
				rwork[i + iy].im = rwork[i].im - temp_im;
				rwork[i].re += temp_re;
				rwork[i].im += temp_im;
			}

			istart = 1;
			for (j = ju; j < 64; j += ju) {
				twid_re = costab[j];
				twid_im = sintab[j];
				i = istart;
				ihi = istart + iheight;
				while (i < ihi) {
					temp_re = twid_re * rwork[i + iy].re - twid_im * rwork[i + iy].im;
					temp_im = twid_re * rwork[i + iy].im + twid_im * rwork[i + iy].re;
					rwork[i + iy].re = rwork[i].re - temp_re;
					rwork[i + iy].im = rwork[i].im - temp_im;
					rwork[i].re += temp_re;
					rwork[i].im += temp_im;
					i += xoff;
				}

				istart++;
			}

			ju /= 2;
			iy = xoff;
			xoff += xoff;
			iheight -= iy;
		}

		memcpy(&y[(k << 7) + -128], &rwork[0], sizeof(creal_T) << 7);
	}
}

//
// Arguments    : const creal_T x[16384]
//                int xoffInit
//                const double costab[65]
//                const double sintab[65]
//                creal_T y[128]
// Return Type  : void
//
static void r2br_r2dit_trig_impl(const creal_T x[16384], int xoffInit, const
	double costab[65], const double sintab[65], creal_T y[128])
{
	int ix;
	int ju;
	int iy;
	int i;
	boolean_T tst;
	double temp_re;
	double temp_im;
	int iheight;
	int istart;
	int j;
	double twid_re;
	double twid_im;
	int ihi;
	ix = xoffInit;
	ju = 0;
	iy = 0;
	for (i = 0; i < 127; i++) {
		y[iy] = x[ix];
		iy = 128;
		tst = true;
		while (tst) {
			iy >>= 1;
			ju ^= iy;
			tst = ((ju & iy) == 0);
		}

		iy = ju;
		ix++;
	}

	y[iy] = x[ix];
	for (i = 0; i <= 127; i += 2) {
		temp_re = y[i + 1].re;
		temp_im = y[i + 1].im;
		y[i + 1].re = y[i].re - y[i + 1].re;
		y[i + 1].im = y[i].im - y[i + 1].im;
		y[i].re += temp_re;
		y[i].im += temp_im;
	}

	iy = 2;
	ix = 4;
	ju = 32;
	iheight = 125;
	while (ju > 0) {
		for (i = 0; i < iheight; i += ix) {
			temp_re = y[i + iy].re;
			temp_im = y[i + iy].im;
			y[i + iy].re = y[i].re - temp_re;
			y[i + iy].im = y[i].im - temp_im;
			y[i].re += temp_re;
			y[i].im += temp_im;
		}

		istart = 1;
		for (j = ju; j < 64; j += ju) {
			twid_re = costab[j];
			twid_im = sintab[j];
			i = istart;
			ihi = istart + iheight;
			while (i < ihi) {
				temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
				temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
				y[i + iy].re = y[i].re - temp_re;
				y[i + iy].im = y[i].im - temp_im;
				y[i].re += temp_re;
				y[i].im += temp_im;
				i += ix;
			}

			istart++;
		}

		ju /= 2;
		iy = ix;
		ix += ix;
		iheight -= iy;
	}
}

//
// Arguments    : const double A[16384]
//                double B[16384]
// Return Type  : void
//
static void rot90(const double A[16384], double B[16384])
{
	int i;
	int j;
	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			B[i + (j << 7)] = A[j + ((127 - i) << 7)];
		}
	}
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
	double y;
	double a;
	double b;
	a = std::abs(u0);
	b = std::abs(u1);
	if (a < b) {
		a /= b;
		y = b * std::sqrt(a * a + 1.0);
	}
	else if (a > b) {
		b /= a;
		y = a * std::sqrt(b * b + 1.0);
	}
	else if (rtIsNaN(b)) {
		y = b;
	}
	else {
		y = a * 1.4142135623730951;
	}

	return y;
}

//
// Arguments    : const emxArray_cell_wrap_1 *image_grids
//                double PSF_grid_factor
//                emxArray_real_T *Simulated_IMG
// Return Type  : void
//
void IMG_grids(const emxArray_cell_wrap_1 *image_grids, double PSF_grid_factor,
	emxArray_real_T *Simulated_IMG)
{
	int i9;
	int loop_ub;
	int i;
	emxArray_real_T *r16;
	int j;
	int nx;
	short iv0[2];
	i9 = Simulated_IMG->size[0] * Simulated_IMG->size[1];
	Simulated_IMG->size[0] = image_grids->data[0].f1->size[0];
	Simulated_IMG->size[1] = image_grids->data[0].f1->size[1];
	emxEnsureCapacity_real_T(Simulated_IMG, i9);
	loop_ub = image_grids->data[0].f1->size[0] * image_grids->data[0].f1->size[1];
	for (i9 = 0; i9 < loop_ub; i9++) {
		Simulated_IMG->data[i9] = 0.0;
	}

	i = 0;
	emxInit_real_T(&r16, 2);
	while (i <= (int)PSF_grid_factor - 1) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			nx = image_grids->data[i + image_grids->size[0] * j].f1->size[0] *
				image_grids->data[i + image_grids->size[0] * j].f1->size[1];
			for (i9 = 0; i9 < 2; i9++) {
				iv0[i9] = (short)image_grids->data[i + image_grids->size[0] * j]
					.f1->size[i9];
			}

			i9 = r16->size[0] * r16->size[1];
			r16->size[0] = iv0[0];
			r16->size[1] = iv0[1];
			emxEnsureCapacity_real_T(r16, i9);
			for (loop_ub = 0; loop_ub < nx; loop_ub++) {
				r16->data[loop_ub] = std::abs(image_grids->data[i + image_grids->size[0]
					* j].f1->data[loop_ub]);
			}

			loop_ub = r16->size[0] * r16->size[1] - 1;
			i9 = Simulated_IMG->size[0] * Simulated_IMG->size[1];
			Simulated_IMG->size[0] = r16->size[0];
			Simulated_IMG->size[1] = r16->size[1];
			emxEnsureCapacity_real_T(Simulated_IMG, i9);
			for (i9 = 0; i9 <= loop_ub; i9++) {
				Simulated_IMG->data[i9] += r16->data[i9];
			}
		}

		i++;
	}

	emxFree_real_T(&r16);
}

//
// Arguments    : double PSF_grid_factor
//                const creal_T otf1[16384]
//                const creal_T otf3[16384]
//                const creal_T otf5[16384]
//                const creal_T otf11[16384]
//                const creal_T otf13[16384]
//                const creal_T otf15[16384]
//                const creal_T otf21[16384]
//                const creal_T otf23[16384]
//                const creal_T otf25[16384]
//                emxArray_cell_wrap_2 *OTF
// Return Type  : void
//
void OTF_grids(double PSF_grid_factor, const creal_T otf1[16384], const creal_T
	otf3[16384], const creal_T otf5[16384], const creal_T otf11[16384],
	const creal_T otf13[16384], const creal_T otf15[16384], const
	creal_T otf21[16384], const creal_T otf23[16384], const creal_T
	otf25[16384], emxArray_cell_wrap_2 *OTF)
{
	int k;
	int i;
	double upsampling_factor;
	int j;
	emxArray_creal_T *M_up;
	creal_T b_otf1[9];
	int l;
	k = OTF->size[0] * OTF->size[1];
	OTF->size[0] = (int)PSF_grid_factor;
	OTF->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_2(OTF, k);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			for (k = 0; k < 16384; k++) {
				OTF->data[i + OTF->size[0] * j].f1[k].re = 0.0;
				OTF->data[i + OTF->size[0] * j].f1[k].im = 0.0;
			}
		}
	}

	upsampling_factor = PSF_grid_factor / 3.0;
	emxInit_creal_T(&M_up, 2);
	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			b_otf1[0] = otf1[i + (j << 7)];
			b_otf1[3] = otf3[i + (j << 7)];
			b_otf1[6] = otf5[i + (j << 7)];
			b_otf1[1] = otf11[i + (j << 7)];
			b_otf1[4] = otf13[i + (j << 7)];
			b_otf1[7] = otf15[i + (j << 7)];
			b_otf1[2] = otf21[i + (j << 7)];
			b_otf1[5] = otf23[i + (j << 7)];
			b_otf1[8] = otf25[i + (j << 7)];
			b_interpImg(b_otf1, upsampling_factor, M_up);
			k = OTF->size[0] * OTF->size[1];
			OTF->size[0] = (int)PSF_grid_factor;
			OTF->size[1] = (int)PSF_grid_factor;
			emxEnsureCapacity_cell_wrap_2(OTF, k);
			for (k = 0; k < (int)PSF_grid_factor; k++) {
				for (l = 0; l < (int)PSF_grid_factor; l++) {
					OTF->data[k + OTF->size[0] * l].f1[i + (j << 7)] = M_up->data[k +
						M_up->size[0] * l];
				}
			}
		}
	}

	emxFree_creal_T(&M_up);
}

//
// Arguments    : const emxArray_cell_wrap_2 *OTF
//                double PSF_grid_factor
//                double img_ht_x
//                const emxArray_real_T *imageArray
//                double rms
//                emxArray_cell_wrap_3 *PSF_final
// Return Type  : void
//
void PSF_grids(const emxArray_cell_wrap_2 *OTF, double PSF_grid_factor, double
	img_ht_x, const emxArray_real_T *imageArray, double rms,
	emxArray_cell_wrap_3 *PSF_final)
{
	emxArray_cell_wrap_2 *PSF;
	int dim;
	int i;
	int j;
	double padding;
	static creal_T dcv0[16384];
	static creal_T dcv1[16384];
	int i11;
	double b_padding[2];
	emxInit_cell_wrap_2(&PSF, 2);
	dim = PSF->size[0] * PSF->size[1];
	PSF->size[0] = (int)PSF_grid_factor;
	PSF->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_2(PSF, dim);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			for (dim = 0; dim < 16384; dim++) {
				dcv0[dim] = OTF->data[i + OTF->size[0] * j].f1[dim];
			}

			b_ifftshift(dcv0);
			for (dim = 0; dim < 128; dim++) {
				for (i11 = 0; i11 < 128; i11++) {
					dcv1[i11 + (dim << 7)] = dcv0[dim + (i11 << 7)];
				}
			}

			c_r2br_r2dit_trig(dcv1, dv0, dv1, dcv0);
			for (dim = 0; dim < 128; dim++) {
				for (i11 = 0; i11 < 128; i11++) {
					dcv1[i11 + (dim << 7)] = dcv0[dim + (i11 << 7)];
				}
			}

			c_r2br_r2dit_trig(dcv1, dv0, dv1, PSF->data[i + PSF->size[0] * j].f1);
			for (dim = 0; dim < 2; dim++) {
				eml_fftshift(PSF->data[i + PSF->size[0] * j].f1, dim + 1);
			}
		}
	}

	// bring psf matrix in units of object matrix
	// psf matrix has size 0.113mm, Obj matrix size is 1.8769mm
	// padding psf matrix for the same factor
	padding = std::floor((128.0 * (img_ht_x / rms * (128.0 / (double)
		imageArray->size[0])) - 128.0) / 2.0);

	// sampling theorem
	dim = PSF_final->size[0] * PSF_final->size[1];
	PSF_final->size[0] = (int)PSF_grid_factor;
	PSF_final->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_3(PSF_final, dim);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			b_padding[0] = padding;
			b_padding[1] = padding;
			padarray(PSF->data[i + PSF->size[0] * j].f1, b_padding, PSF_final->data[i
				+ PSF_final->size[0] * j].f1);
		}
	}

	emxFree_cell_wrap_2(&PSF);
}

//
// Arguments    : const emxArray_real_T *imageArray
//                double PSF_grid_factor
//                emxArray_cell_wrap_0 *M
// Return Type  : void
//
void celling(const emxArray_real_T *imageArray, double PSF_grid_factor,
	emxArray_cell_wrap_0 *M)
{
	double r3;
	double c3;
	int i;
	int j;
	r3 = std::ceil((double)imageArray->size[0] / PSF_grid_factor);
	c3 = std::ceil((double)imageArray->size[1] / PSF_grid_factor);
	i = M->size[0] * M->size[1];
	M->size[0] = (int)PSF_grid_factor;
	M->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_0(M, i);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			b_zone(imageArray, ((1.0 + (double)i) - 1.0) * r3 + 1.0, (1.0 + (double)i)
				* r3, ((1.0 + (double)j) - 1.0) * c3 + 1.0, (1.0 + (double)j) * c3,
				M->data[j + M->size[0] * i].f1);
		}
	}
}

//
// Arguments    : const emxArray_cell_wrap_1 *M
//                const emxArray_cell_wrap_1 *PSF
//                double PSF_grid_factor
//                emxArray_cell_wrap_0 *IMG
// Return Type  : void
//
void convolution_function(const emxArray_cell_wrap_1 *M, const
	emxArray_cell_wrap_1 *PSF, double PSF_grid_factor, emxArray_cell_wrap_0 *IMG)
{
	int i;
	int j;
	i = IMG->size[0] * IMG->size[1];
	IMG->size[0] = (int)PSF_grid_factor;
	IMG->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_0(IMG, i);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			conv2(M->data[i + M->size[0] * j].f1, PSF->data[i + PSF->size[0] * j].f1,
				IMG->data[i + IMG->size[0] * j].f1);
		}
	}
}

//
// Arguments    : const emxArray_real_T *imageArray
//                double PSF_grid_factor
//                double img_ht_x
//                double rms
//                const double psf2[16384]
//                const double psf3[16384]
//                const double psf5[16384]
//                emxArray_real_T *Simulated_IMG
// Return Type  : void
//
void final_convol(const emxArray_real_T *imageArray, double PSF_grid_factor,
	double img_ht_x, double rms, const double psf2[16384], const
	double psf3[16384], const double psf5[16384], emxArray_real_T *Simulated_IMG)
{
	double a;
	double b;
	int loop_ub;
	int b_loop_ub;
	emxArray_real_T *b_imageArray;
	int i0;
	emxArray_cell_wrap_0 *Obj;
	int nx;
	static double psf4[16384];
	static double psf8[16384];
	static double psf6[16384];
	static double psf1[16384];
	static double psf7[16384];
	static double psf9[16384];
	double b_psf1[16384];
	static const double dv2[65] = { 0.0, -0.049067674327418015,
	  -0.0980171403295606, -0.14673047445536175, -0.19509032201612825,
	  -0.24298017990326387, -0.29028467725446233, -0.33688985339222005,
	  -0.38268343236508978, -0.42755509343028208, -0.47139673682599764,
	  -0.51410274419322166, -0.55557023301960218, -0.59569930449243336,
	  -0.63439328416364549, -0.67155895484701833, -0.70710678118654757,
	  -0.74095112535495922, -0.773010453362737, -0.80320753148064494,
	  -0.83146961230254524, -0.85772861000027212, -0.881921264348355,
	  -0.90398929312344334, -0.92387953251128674, -0.94154406518302081,
	  -0.95694033573220882, -0.970031253194544, -0.98078528040323043,
	  -0.989176509964781, -0.99518472667219693, -0.99879545620517241, -1.0,
	  -0.99879545620517241, -0.99518472667219693, -0.989176509964781,
	  -0.98078528040323043, -0.970031253194544, -0.95694033573220882,
	  -0.94154406518302081, -0.92387953251128674, -0.90398929312344334,
	  -0.881921264348355, -0.85772861000027212, -0.83146961230254524,
	  -0.80320753148064494, -0.773010453362737, -0.74095112535495922,
	  -0.70710678118654757, -0.67155895484701833, -0.63439328416364549,
	  -0.59569930449243336, -0.55557023301960218, -0.51410274419322166,
	  -0.47139673682599764, -0.42755509343028208, -0.38268343236508978,
	  -0.33688985339222005, -0.29028467725446233, -0.24298017990326387,
	  -0.19509032201612825, -0.14673047445536175, -0.0980171403295606,
	  -0.049067674327418015, -0.0 };

	static creal_T otf9[16384];
	static creal_T b_otf9[16384];
	static creal_T otf1[16384];
	static creal_T otf2[16384];
	static creal_T otf3[16384];
	static creal_T otf4[16384];
	static creal_T otf5[16384];
	static creal_T otf6[16384];
	static creal_T otf7[16384];
	static creal_T otf8[16384];
	emxArray_cell_wrap_2 *OTF;
	emxArray_cell_wrap_2 *PSF;
	int i;
	int j;
	emxArray_cell_wrap_3 *b_PSF;
	emxArray_creal_T *c_PSF;
	double padding[2];
	emxArray_cell_wrap_3 *image_grids;
	unsigned int uv0[2];
	a = (double)imageArray->size[0] - b_mod((double)imageArray->size[0],
		PSF_grid_factor);
	b = (double)imageArray->size[1] - b_mod((double)imageArray->size[1],
		PSF_grid_factor);
	if (1.0 > a) {
		loop_ub = 0;
	}
	else {
		loop_ub = (int)a;
	}

	if (1.0 > b) {
		b_loop_ub = 0;
	}
	else {
		b_loop_ub = (int)b;
	}

	emxInit_real_T(&b_imageArray, 2);

	// imagesc(imageArray)
	i0 = b_imageArray->size[0] * b_imageArray->size[1];
	b_imageArray->size[0] = loop_ub;
	b_imageArray->size[1] = b_loop_ub;
	emxEnsureCapacity_real_T(b_imageArray, i0);
	for (i0 = 0; i0 < b_loop_ub; i0++) {
		for (nx = 0; nx < loop_ub; nx++) {
			b_imageArray->data[nx + b_imageArray->size[0] * i0] = imageArray->data[nx
				+ imageArray->size[0] * i0];
		}
	}

	emxInit_cell_wrap_0(&Obj, 2);
	b_celling(b_imageArray, PSF_grid_factor, Obj);

	// if we have psf 2,3 and 5. I need 1,4,6,7,8,9
	//  2 ccw90 4
	//  4 ccw90 8
	//  8 ccw90 6
	//  3 ccw90 1
	//  1 ccw90 7
	//  7 ccw90 9
	rot90(psf2, psf4);
	rot90(psf4, psf8);
	rot90(psf8, psf6);
	rot90(psf3, psf1);
	rot90(psf1, psf7);
	rot90(psf7, psf9);
	ifftshift(psf1);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_psf1[nx + (i0 << 7)] = psf1[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(b_psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf1);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf1, b_loop_ub + 1);
	}

	memcpy(&psf1[0], &psf2[0], sizeof(double) << 14);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf1, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_psf1[nx + (i0 << 7)] = psf1[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(b_psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf2);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf2, b_loop_ub + 1);
	}

	memcpy(&psf1[0], &psf3[0], sizeof(double) << 14);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf1, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_psf1[nx + (i0 << 7)] = psf1[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(b_psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf3);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf3, b_loop_ub + 1);
	}

	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf4, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			psf1[nx + (i0 << 7)] = psf4[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf4);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf4, b_loop_ub + 1);
	}

	memcpy(&psf1[0], &psf5[0], sizeof(double) << 14);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf1, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_psf1[nx + (i0 << 7)] = psf1[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(b_psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf5);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf5, b_loop_ub + 1);
	}

	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf6, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			psf1[nx + (i0 << 7)] = psf6[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf6);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf6, b_loop_ub + 1);
	}

	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf7, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			psf1[nx + (i0 << 7)] = psf7[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf7);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf7, b_loop_ub + 1);
	}

	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf8, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			psf1[nx + (i0 << 7)] = psf8[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf8);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf8, b_loop_ub + 1);
	}

	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_ifftshift(psf9, b_loop_ub + 1);
	}

	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			psf1[nx + (i0 << 7)] = psf9[i0 + (nx << 7)];
		}
	}

	r2br_r2dit_trig(psf1, dv0, dv2, otf9);
	for (i0 = 0; i0 < 128; i0++) {
		for (nx = 0; nx < 128; nx++) {
			b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
		}
	}

	b_r2br_r2dit_trig(b_otf9, dv0, dv2, otf9);
	for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
		eml_fftshift(otf9, b_loop_ub + 1);
	}

	emxInit_cell_wrap_2(&OTF, 2);
	emxInit_cell_wrap_2(&PSF, 2);
	OTF_grids(PSF_grid_factor, otf1, otf2, otf3, otf4, otf5, otf6, otf7, otf8,
		otf9, OTF);
	i0 = PSF->size[0] * PSF->size[1];
	PSF->size[0] = (int)PSF_grid_factor;
	PSF->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_2(PSF, i0);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			for (i0 = 0; i0 < 16384; i0++) {
				otf9[i0] = OTF->data[i + OTF->size[0] * j].f1[i0];
			}

			b_ifftshift(otf9);
			for (i0 = 0; i0 < 128; i0++) {
				for (nx = 0; nx < 128; nx++) {
					b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
				}
			}

			c_r2br_r2dit_trig(b_otf9, dv0, dv1, otf9);
			for (i0 = 0; i0 < 128; i0++) {
				for (nx = 0; nx < 128; nx++) {
					b_otf9[nx + (i0 << 7)] = otf9[i0 + (nx << 7)];
				}
			}

			c_r2br_r2dit_trig(b_otf9, dv0, dv1, PSF->data[i + PSF->size[0] * j].f1);
			for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
				eml_fftshift(PSF->data[i + PSF->size[0] * j].f1, b_loop_ub + 1);
			}
		}
	}

	emxFree_cell_wrap_2(&OTF);
	emxInit_cell_wrap_3(&b_PSF, 2);

	// bring psf matrix in units of object matrix
	// psf matrix has size 0.113mm, Obj matrix size is 1.8769mm
	// padding psf matrix for the same factor
	a = std::floor((128.0 * (img_ht_x / rms * (128.0 / (double)loop_ub)) - 128.0) /
		2.0);

	// sampling theorem
	i0 = b_PSF->size[0] * b_PSF->size[1];
	b_PSF->size[0] = (int)PSF_grid_factor;
	b_PSF->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_3(b_PSF, i0);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			padding[0] = a;
			padding[1] = a;
			padarray(PSF->data[i + PSF->size[0] * j].f1, padding, b_PSF->data[i +
				b_PSF->size[0] * j].f1);
		}
	}

	emxFree_cell_wrap_2(&PSF);
	a = (double)loop_ub / (double)b_PSF->data[0].f1->size[0];
	i = 0;
	emxInit_creal_T(&c_PSF, 2);
	while (i <= (int)PSF_grid_factor - 1) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			i0 = c_PSF->size[0] * c_PSF->size[1];
			c_PSF->size[0] = b_PSF->data[i + b_PSF->size[0] * j].f1->size[0];
			c_PSF->size[1] = b_PSF->data[i + b_PSF->size[0] * j].f1->size[1];
			emxEnsureCapacity_creal_T(c_PSF, i0);
			loop_ub = b_PSF->data[i + b_PSF->size[0] * j].f1->size[0] * b_PSF->data[i
				+ b_PSF->size[0] * j].f1->size[1];
			for (i0 = 0; i0 < loop_ub; i0++) {
				c_PSF->data[i0] = b_PSF->data[i + b_PSF->size[0] * j].f1->data[i0];
			}

			c_interpImg(c_PSF, a, b_PSF->data[i + b_PSF->size[0] * j].f1);
		}

		i++;
	}

	emxFree_creal_T(&c_PSF);
	emxInit_cell_wrap_3(&image_grids, 2);
	i0 = image_grids->size[0] * image_grids->size[1];
	image_grids->size[0] = (int)PSF_grid_factor;
	image_grids->size[1] = (int)PSF_grid_factor;
	emxEnsureCapacity_cell_wrap_3(image_grids, i0);
	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			b_conv2(Obj->data[i + Obj->size[0] * j].f1, b_PSF->data[i + b_PSF->size[0]
				* j].f1, image_grids->data[i + image_grids->size[0] * j].f1);

			std::cout << j + 1 << "/7 locally completed" << std::endl;

		}
		std::cout << i + 1 << "/7 globaly completed" << std::endl;
	}

	emxFree_cell_wrap_3(&b_PSF);
	emxFree_cell_wrap_0(&Obj);
	i0 = Simulated_IMG->size[0] * Simulated_IMG->size[1];
	Simulated_IMG->size[0] = image_grids->data[0].f1->size[0];
	Simulated_IMG->size[1] = image_grids->data[0].f1->size[1];
	emxEnsureCapacity_real_T(Simulated_IMG, i0);
	loop_ub = image_grids->data[0].f1->size[0] * image_grids->data[0].f1->size[1];
	for (i0 = 0; i0 < loop_ub; i0++) {
		Simulated_IMG->data[i0] = 0.0;
	}

	for (i = 0; i < (int)PSF_grid_factor; i++) {
		for (j = 0; j < (int)PSF_grid_factor; j++) {
			nx = image_grids->data[i + image_grids->size[0] * j].f1->size[0] *
				image_grids->data[i + image_grids->size[0] * j].f1->size[1];
			for (i0 = 0; i0 < 2; i0++) {
				uv0[i0] = (unsigned int)image_grids->data[i + image_grids->size[0] * j].
					f1->size[i0];
			}

			i0 = b_imageArray->size[0] * b_imageArray->size[1];
			b_imageArray->size[0] = (int)uv0[0];
			b_imageArray->size[1] = (int)uv0[1];
			emxEnsureCapacity_real_T(b_imageArray, i0);
			for (b_loop_ub = 0; b_loop_ub < nx; b_loop_ub++) {
				b_imageArray->data[b_loop_ub] = rt_hypotd_snf(image_grids->data[i +
					image_grids->size[0] * j].f1->data[b_loop_ub].re, image_grids->data[i
					+ image_grids->size[0] * j].f1->data[b_loop_ub].im);
			}

			loop_ub = b_imageArray->size[0] * b_imageArray->size[1] - 1;
			i0 = Simulated_IMG->size[0] * Simulated_IMG->size[1];
			Simulated_IMG->size[0] = b_imageArray->size[0];
			Simulated_IMG->size[1] = b_imageArray->size[1];
			emxEnsureCapacity_real_T(Simulated_IMG, i0);
			for (i0 = 0; i0 <= loop_ub; i0++) {
				Simulated_IMG->data[i0] += b_imageArray->data[i0];
			}
		}
	}

	//emxFree_real_T(&b_imageArray);
	//emxFree_cell_wrap_3(&image_grids);
}

//
// Arguments    : void
// Return Type  : void
//
void img_sim_sec_version_initialize()
{
	rt_InitInfAndNaN(8U);
	omp_init_nest_lock(&emlrtNestLockGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void img_sim_sec_version_terminate()
{
	omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

//
// // Get some necessary variables first
// Arguments    : const emxArray_creal_T *im
//                double ratio
//                emxArray_creal_T *out
// Return Type  : void
//
void interpImg(const emxArray_creal_T *im, double ratio, emxArray_creal_T *out)
{
	emxArray_real_T *y;
	int in_cols;
	int in_rows;
	double out_rows;
	double out_cols;
	int i10;
	int loop_ub;
	emxArray_real_T *b_y;
	emxArray_real_T *cf;
	emxArray_real_T *rf;
	emxArray_real_T *c;
	emxArray_real_T *r;
	int end;
	int trueCount;
	int i;
	emxArray_int32_T *r17;
	emxArray_int32_T *r18;
	emxArray_int32_T *r19;
	emxArray_int32_T *r20;
	short siz_idx_0;
	short b_siz_idx_0;
	short c_siz_idx_0;
	short d_siz_idx_0;
	emxArray_creal_T *chan;
	emxArray_creal_T *r21;
	emxArray_creal_T *r22;
	emxArray_creal_T *r23;
	emxArray_creal_T *r24;
	double re;
	double b_im;
	double b_re;
	double c_im;
	double c_re;
	double d_im;
	emxInit_real_T(&y, 2);
	in_cols = im->size[1];
	in_rows = im->size[0];
	out_rows = (double)im->size[0] * ratio;
	out_cols = (double)im->size[1] * ratio;

	//      %// Let S_R = R / R'
	//      S_R = in_rows / out_rows;
	//      %// Let S_C = C / C'
	//      S_C = in_cols / out_cols;
	// // Define grid of co-ordinates in our image
	// // Generate (x,y) pairs for each point in our image
	if (rtIsNaN(out_cols)) {
		i10 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i10);
		y->data[0] = rtNaN;
	}
	else if (out_cols < 1.0) {
		i10 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 0;
		emxEnsureCapacity_real_T(y, i10);
	}
	else if (rtIsInf(out_cols) && (1.0 == out_cols)) {
		i10 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = 1;
		emxEnsureCapacity_real_T(y, i10);
		y->data[0] = rtNaN;
	}
	else {
		i10 = y->size[0] * y->size[1];
		y->size[0] = 1;
		y->size[1] = (int)std::floor(out_cols - 1.0) + 1;
		emxEnsureCapacity_real_T(y, i10);
		loop_ub = (int)std::floor(out_cols - 1.0);
		for (i10 = 0; i10 <= loop_ub; i10++) {
			y->data[y->size[0] * i10] = 1.0 + (double)i10;
		}
	}

	emxInit_real_T(&b_y, 2);
	if (rtIsNaN(out_rows)) {
		i10 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i10);
		b_y->data[0] = rtNaN;
	}
	else if (out_rows < 1.0) {
		i10 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 0;
		emxEnsureCapacity_real_T(b_y, i10);
	}
	else if (rtIsInf(out_rows) && (1.0 == out_rows)) {
		i10 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = 1;
		emxEnsureCapacity_real_T(b_y, i10);
		b_y->data[0] = rtNaN;
	}
	else {
		i10 = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = (int)std::floor(out_rows - 1.0) + 1;
		emxEnsureCapacity_real_T(b_y, i10);
		loop_ub = (int)std::floor(out_rows - 1.0);
		for (i10 = 0; i10 <= loop_ub; i10++) {
			b_y->data[b_y->size[0] * i10] = 1.0 + (double)i10;
		}
	}

	emxInit_real_T(&cf, 2);
	emxInit_real_T(&rf, 2);
	meshgrid(y, b_y, cf, rf);

	// // Let r_f = r'*S_R for r = 1,...,R'
	// // Let c_f = c'*S_C for c = 1,...,C'
	loop_ub = cf->size[0] * cf->size[1] - 1;
	i10 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i10);
	emxFree_real_T(&b_y);
	emxFree_real_T(&y);
	for (i10 = 0; i10 <= loop_ub; i10++) {
		cf->data[i10] /= ratio;
	}

	loop_ub = rf->size[0] * rf->size[1] - 1;
	i10 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i10);
	for (i10 = 0; i10 <= loop_ub; i10++) {
		rf->data[i10] /= ratio;
	}

	emxInit_real_T(&c, 2);

	// // Let r = floor(rf) and c = floor(cf)
	i10 = c->size[0] * c->size[1];
	c->size[0] = cf->size[0];
	c->size[1] = cf->size[1];
	emxEnsureCapacity_real_T(c, i10);
	loop_ub = cf->size[0] * cf->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		c->data[i10] = cf->data[i10];
	}

	emxInit_real_T(&r, 2);
	b_floor(c);
	i10 = r->size[0] * r->size[1];
	r->size[0] = rf->size[0];
	r->size[1] = rf->size[1];
	emxEnsureCapacity_real_T(r, i10);
	loop_ub = rf->size[0] * rf->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		r->data[i10] = rf->data[i10];
	}

	b_floor(r);

	// // Any values out of range, cap
	end = r->size[0] * r->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r17, 1);
	i10 = r17->size[0];
	r17->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r17, i10);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] < 1.0) {
			r17->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r17->size[0] - 1;
	for (i10 = 0; i10 <= loop_ub; i10++) {
		r->data[r17->data[i10] - 1] = 1.0;
	}

	emxFree_int32_T(&r17);
	end = c->size[0] * c->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r18, 1);
	i10 = r18->size[0];
	r18->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r18, i10);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] < 1.0) {
			r18->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r18->size[0] - 1;
	for (i10 = 0; i10 <= loop_ub; i10++) {
		c->data[r18->data[i10] - 1] = 1.0;
	}

	emxFree_int32_T(&r18);
	end = r->size[0] * r->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > (double)in_rows - 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r19, 1);
	i10 = r19->size[0];
	r19->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r19, i10);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (r->data[i] > (double)in_rows - 1.0) {
			r19->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r19->size[0] - 1;
	for (i10 = 0; i10 <= loop_ub; i10++) {
		r->data[r19->data[i10] - 1] = (short)(im->size[0] - 1);
	}

	emxFree_int32_T(&r19);
	end = c->size[0] * c->size[1] - 1;
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > (double)in_cols - 1.0) {
			trueCount++;
		}
	}

	emxInit_int32_T(&r20, 1);
	i10 = r20->size[0];
	r20->size[0] = trueCount;
	emxEnsureCapacity_int32_T(r20, i10);
	trueCount = 0;
	for (i = 0; i <= end; i++) {
		if (c->data[i] > (double)in_cols - 1.0) {
			r20->data[trueCount] = i + 1;
			trueCount++;
		}
	}

	loop_ub = r20->size[0] - 1;
	for (i10 = 0; i10 <= loop_ub; i10++) {
		c->data[r20->data[i10] - 1] = (short)(im->size[1] - 1);
	}

	emxFree_int32_T(&r20);

	// // Let delta_R = rf - r and delta_C = cf - c
	loop_ub = rf->size[0] * rf->size[1] - 1;
	i10 = rf->size[0] * rf->size[1];
	emxEnsureCapacity_real_T(rf, i10);
	for (i10 = 0; i10 <= loop_ub; i10++) {
		rf->data[i10] -= r->data[i10];
	}

	loop_ub = cf->size[0] * cf->size[1] - 1;
	i10 = cf->size[0] * cf->size[1];
	emxEnsureCapacity_real_T(cf, i10);
	for (i10 = 0; i10 <= loop_ub; i10++) {
		cf->data[i10] -= c->data[i10];
	}

	// // Final line of algorithm
	// // Get column major indices for each point we wish
	// // to access
	siz_idx_0 = (short)im->size[0];
	b_siz_idx_0 = (short)im->size[0];
	c_siz_idx_0 = (short)im->size[0];
	d_siz_idx_0 = (short)im->size[0];

	// // Now interpolate
	// // Create output matrix that is the same class as input
	//      out = cast(out, class(im));
	i10 = out->size[0] * out->size[1];
	out->size[0] = (int)out_rows;
	out->size[1] = (int)out_cols;
	emxEnsureCapacity_creal_T(out, i10);
	loop_ub = (int)out_rows * (int)out_cols;
	for (i10 = 0; i10 < loop_ub; i10++) {
		out->data[i10].re = 0.0;
		out->data[i10].im = 0.0;
	}

	emxInit_creal_T(&chan, 2);
	trueCount = im->size[0];
	loop_ub = im->size[0];
	i = im->size[1];
	i10 = chan->size[0] * chan->size[1];
	chan->size[0] = loop_ub;
	chan->size[1] = i;
	emxEnsureCapacity_creal_T(chan, i10);
	for (i10 = 0; i10 < i; i10++) {
		for (end = 0; end < loop_ub; end++) {
			chan->data[end + chan->size[0] * i10] = im->data[end + trueCount * i10];
		}
	}

	emxInit_creal_T(&r21, 2);

	// // Get i'th channel
	// // Interpolate the channel
	i10 = r21->size[0] * r21->size[1];
	r21->size[0] = r->size[0];
	r21->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r21, i10);
	loop_ub = r->size[0] * r->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		r21->data[i10] = chan->data[((int)r->data[i10] + siz_idx_0 * ((int)c->
			data[i10] - 1)) - 1];
	}

	emxInit_creal_T(&r22, 2);
	i10 = r22->size[0] * r22->size[1];
	r22->size[0] = r->size[0];
	r22->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r22, i10);
	loop_ub = r->size[0] * r->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		r22->data[i10] = chan->data[((int)(r->data[i10] + 1.0) + b_siz_idx_0 * ((int)
			c->data[i10] - 1)) - 1];
	}

	emxInit_creal_T(&r23, 2);
	i10 = r23->size[0] * r23->size[1];
	r23->size[0] = r->size[0];
	r23->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r23, i10);
	loop_ub = r->size[0] * r->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		r23->data[i10] = chan->data[((int)r->data[i10] + c_siz_idx_0 * ((int)
			(c->data[i10] + 1.0) - 1)) - 1];
	}

	emxInit_creal_T(&r24, 2);
	i10 = r24->size[0] * r24->size[1];
	r24->size[0] = r->size[0];
	r24->size[1] = r->size[1];
	emxEnsureCapacity_creal_T(r24, i10);
	loop_ub = r->size[0] * r->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		r24->data[i10] = chan->data[((int)(r->data[i10] + 1.0) + d_siz_idx_0 * ((int)
			(c->data[i10] + 1.0) - 1)) - 1];
	}

	emxFree_creal_T(&chan);
	emxFree_real_T(&r);
	emxFree_real_T(&c);
	trueCount = out->size[0];
	loop_ub = r21->size[1];
	for (i10 = 0; i10 < loop_ub; i10++) {
		i = r21->size[0];
		for (end = 0; end < i; end++) {
			out_rows = (1.0 - rf->data[end + rf->size[0] * i10]) * r21->data[end +
				r21->size[0] * i10].re;
			out_cols = (1.0 - rf->data[end + rf->size[0] * i10]) * r21->data[end +
				r21->size[0] * i10].im;
			re = rf->data[end + rf->size[0] * i10] * r22->data[end + r22->size[0] *
				i10].re;
			b_im = rf->data[end + rf->size[0] * i10] * r22->data[end + r22->size[0] *
				i10].im;
			b_re = (1.0 - rf->data[end + rf->size[0] * i10]) * r23->data[end +
				r23->size[0] * i10].re;
			c_im = (1.0 - rf->data[end + rf->size[0] * i10]) * r23->data[end +
				r23->size[0] * i10].im;
			c_re = rf->data[end + rf->size[0] * i10] * r24->data[end + r24->size[0] *
				i10].re;
			d_im = rf->data[end + rf->size[0] * i10] * r24->data[end + r24->size[0] *
				i10].im;
			out->data[end + trueCount * i10].re = ((out_rows * (1.0 - cf->data[end +
				cf->size[0] * i10]) + re * (1.0 - cf->data[end + cf->size[0] * i10])) +
				b_re * cf->data[end + cf->size[0] * i10]) + c_re * cf->data[end +
				cf->size[0] * i10];
			out->data[end + trueCount * i10].im = ((out_cols * (1.0 - cf->data[end +
				cf->size[0] * i10]) + b_im * (1.0 - cf->data[end + cf->size[0] * i10]))
				+ c_im * cf->data[end + cf->size[0] * i10]) + d_im * cf->data[end +
				cf->size[0] * i10];
		}
	}

	emxFree_creal_T(&r24);
	emxFree_creal_T(&r23);
	emxFree_creal_T(&r22);
	emxFree_creal_T(&r21);
	emxFree_real_T(&rf);
	emxFree_real_T(&cf);
}

//
// Arguments    : const emxArray_real_T *Obj
//                double r1
//                double r2
//                double c1
//                double c2
//                emxArray_real_T *f
// Return Type  : void
//
void zone(const emxArray_real_T *Obj, double r1, double r2, double c1, double c2,
	emxArray_real_T *f)
{
	int i;
	int j;
	i = f->size[0] * f->size[1];
	f->size[0] = Obj->size[0];
	f->size[1] = Obj->size[1];
	emxEnsureCapacity_real_T(f, i);
	for (i = 0; i < Obj->size[0]; i++) {
		for (j = 0; j < Obj->size[1]; j++) {
			if ((1.0 + (double)i >= r1) && (1.0 + (double)i <= r2) && (1.0 + (double)j
				>= c1) && (1.0 + (double)j <= c2)) {
				f->data[i + f->size[0] * j] = Obj->data[i + Obj->size[0] * j];
			}
			else {
				f->data[i + f->size[0] * j] = 0.0;
			}
		}
	}
}


//rt_nonfinite.cpp

/*
* Abstract:
*MATLAB for code generation function to initialize non - finites,
*(Inf, NaN and -Inf).
* /
//#include "rt_nonfinite.h"
//#include "img_sim_sec_version.h"
//#include <cmath>
//#include <limits>

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
	(void)realSize;
	rtNaN = std::numeric_limits<real_T>::quiet_NaN();
	rtNaNF = std::numeric_limits<real32_T>::quiet_NaN();
	rtInf = std::numeric_limits<real_T>::infinity();
	rtInfF = std::numeric_limits<real32_T>::infinity();
	rtMinusInf = -std::numeric_limits<real_T>::infinity();
	rtMinusInfF = -std::numeric_limits<real32_T>::infinity();
}

/* Function: rtIsInf ==================================================
 * Abstract:
 * Test if value is infinite
 */
boolean_T rtIsInf(real_T value)
{
	return ((value == rtInf || value == rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 * Test if single-precision value is infinite
 */
boolean_T rtIsInfF(real32_T value)
{
	return(((value) == rtInfF || (value) == rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 * Test if value is not a number
 */
boolean_T rtIsNaN(real_T value)
{
	return (value != value) ? 1U : 0U;
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 * Test if single-precision value is not a number
 */
boolean_T rtIsNaNF(real32_T value)
{
	return (value != value) ? 1U : 0U;
}

/*
 * File trailer for rt_nonfinite.cpp
 *
 * [EOF]
 */
 //end


 //rtGetInf.cpp
 /*
  * Abstract:
  *       MATLAB for code generation function to initialize non-finite, Inf and MinusInf
  */
  //#include "img_sim_sec_version.h"

   /* Function: rtGetInf ==================================================
	* Abstract:
	* Initialize rtInf needed by the generated code.
	*/
real_T rtGetInf(void)
{
	return rtInf;
}

/* Function: rtGetInfF ==================================================
 * Abstract:
 * Initialize rtInfF needed by the generated code.
 */
real32_T rtGetInfF(void)
{
	return rtInfF;
}

/* Function: rtGetMinusInf ==================================================
 * Abstract:
 * Initialize rtMinusInf needed by the generated code.
 */
real_T rtGetMinusInf(void)
{
	return rtMinusInf;
}

/* Function: rtGetMinusInfF ==================================================
 * Abstract:
 * Initialize rtMinusInfF needed by the generated code.
 */
real32_T rtGetMinusInfF(void)
{
	return rtMinusInfF;
}

/*
 * File trailer for rtGetInf.cpp
 *
 * [EOF]
 */

 //end


 //rtGetNan.cpp
 /*
  * Abstract:
  *       MATLAB for code generation function to initialize non-finite, NaN
  */
  //#include "img_sim_sec_version.h"

   /* Function: rtGetNaN ==================================================
	* Abstract:
	* Initialize rtNaN needed by the generated code.
	* NaN is initialized as non-signaling. Assumes IEEE.
	*/
real_T rtGetNaN(void)
{
	return rtNaN;
}

/* Function: rtGetNaNF ==================================================
 * Abstract:
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
	return rtNaNF;
}

/*
 * File trailer for rtGetNaN.cpp
 *
 * [EOF]
 */
 //end



 //img_sim_sec_version_emxutil.cpp
 //
 // Academic License - for use in teaching, academic research, and meeting
 // course requirements at degree granting institutions only.  Not for
 // government, commercial, or other organizational use.
 // File: img_sim_sec_version_emxutil.cpp
 //
 // MATLAB Coder version            : 4.0
 // C/C++ source code generated on  : 03-Apr-2019 14:58:18
 //

 // Include Files
 //#include <stdlib.h>
 //#include <string.h>
 //#include "rt_nonfinite.h"
 //#include "img_sim_sec_version.h"
 //#include "img_sim_sec_version_emxutil.h"

 // Function Declarations
static void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
	int toIndex);
static void emxExpand_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int fromIndex,
	int toIndex);
static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct);
static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct);
static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct);
static void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
	int toIndex);
static void emxTrim_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int fromIndex,
	int toIndex);

// Function Definitions

//
// Arguments    : emxArray_cell_wrap_0 *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
	int toIndex)
{
	int i;
	for (i = fromIndex; i < toIndex; i++) {
		emxInitStruct_cell_wrap_0(&emxArray->data[i]);
	}
}

//
// Arguments    : emxArray_cell_wrap_3 *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxExpand_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int fromIndex,
	int toIndex)
{
	int i;
	for (i = fromIndex; i < toIndex; i++) {
		emxInitStruct_cell_wrap_3(&emxArray->data[i]);
	}
}

//
// Arguments    : cell_wrap_0 *pStruct
// Return Type  : void
//
static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
	emxFree_real_T(&pStruct->f1);
}

//
// Arguments    : cell_wrap_1 *pStruct
// Return Type  : void
//
static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
	emxFree_real_T(&pStruct->f1);
}

//
// Arguments    : cell_wrap_3 *pStruct
// Return Type  : void
//
static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
	emxFree_creal_T(&pStruct->f1);
}

//
// Arguments    : cell_wrap_0 *pStruct
// Return Type  : void
//
static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
	emxInit_real_T(&pStruct->f1, 2);
}

//
// Arguments    : cell_wrap_3 *pStruct
// Return Type  : void
//
static void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
	emxInit_creal_T(&pStruct->f1, 2);
}

//
// Arguments    : emxArray_cell_wrap_0 *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
	int toIndex)
{
	int i;
	for (i = fromIndex; i < toIndex; i++) {
		emxFreeStruct_cell_wrap_0(&emxArray->data[i]);
	}
}

//
// Arguments    : emxArray_cell_wrap_3 *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxTrim_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int fromIndex,
	int toIndex)
{
	int i;
	for (i = fromIndex; i < toIndex; i++) {
		emxFreeStruct_cell_wrap_3(&emxArray->data[i]);
	}
}

//
// Arguments    : emxArray_cell_wrap_0 *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(cell_wrap_0));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(cell_wrap_0) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (cell_wrap_0 *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}

	if (oldNumel > newNumel) {
		emxTrim_cell_wrap_0(emxArray, newNumel, oldNumel);
	}
	else {
		if (oldNumel < newNumel) {
			emxExpand_cell_wrap_0(emxArray, oldNumel, newNumel);
		}
	}
}

//
// Arguments    : emxArray_cell_wrap_2 *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(cell_wrap_2));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(cell_wrap_2) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (cell_wrap_2 *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_cell_wrap_3 *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(cell_wrap_3));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(cell_wrap_3) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (cell_wrap_3 *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}

	if (oldNumel > newNumel) {
		emxTrim_cell_wrap_3(emxArray, newNumel, oldNumel);
	}
	else {
		if (oldNumel < newNumel) {
			emxExpand_cell_wrap_3(emxArray, oldNumel, newNumel);
		}
	}
}

//
// Arguments    : emxArray_creal_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(creal_T));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(creal_T) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (creal_T *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_creal_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_creal_T1(emxArray_creal_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(creal_T));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(creal_T) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (creal_T *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_int32_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(int));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(int) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (int *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_real_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(double));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(double) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (double *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_real_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_real_T1(emxArray_real_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(double));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(double) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (double *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_cell_wrap_0 **pEmxArray
// Return Type  : void
//
void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
	int numEl;
	int i;
	if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
		if ((*pEmxArray)->data != (cell_wrap_0 *)NULL) {
			numEl = 1;
			for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
				numEl *= (*pEmxArray)->size[i];
			}

			for (i = 0; i < numEl; i++) {
				emxFreeStruct_cell_wrap_0(&(*pEmxArray)->data[i]);
			}

			if ((*pEmxArray)->canFreeData) {
				free((void *)(*pEmxArray)->data);
			}
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_cell_wrap_0 *)NULL;
	}
}

//
// Arguments    : emxArray_cell_wrap_1 **pEmxArray
// Return Type  : void
//
void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray)
{
	int numEl;
	int i;
	if (*pEmxArray != (emxArray_cell_wrap_1 *)NULL) {
		if ((*pEmxArray)->data != (cell_wrap_1 *)NULL) {
			numEl = 1;
			for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
				numEl *= (*pEmxArray)->size[i];
			}

			for (i = 0; i < numEl; i++) {
				emxFreeStruct_cell_wrap_1(&(*pEmxArray)->data[i]);
			}

			if ((*pEmxArray)->canFreeData) {
				free((void *)(*pEmxArray)->data);
			}
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_cell_wrap_1 *)NULL;
	}
}

//
// Arguments    : emxArray_cell_wrap_2 **pEmxArray
// Return Type  : void
//
void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
	if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
		if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) && (*pEmxArray)->canFreeData)
		{
			free((void *)(*pEmxArray)->data);
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_cell_wrap_2 *)NULL;
	}
}

//
// Arguments    : emxArray_cell_wrap_3 **pEmxArray
// Return Type  : void
//
void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
	int numEl;
	int i;
	if (*pEmxArray != (emxArray_cell_wrap_3 *)NULL) {
		if ((*pEmxArray)->data != (cell_wrap_3 *)NULL) {
			numEl = 1;
			for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
				numEl *= (*pEmxArray)->size[i];
			}

			for (i = 0; i < numEl; i++) {
				emxFreeStruct_cell_wrap_3(&(*pEmxArray)->data[i]);
			}

			if ((*pEmxArray)->canFreeData) {
				free((void *)(*pEmxArray)->data);
			}
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_cell_wrap_3 *)NULL;
	}
}

//
// Arguments    : emxArray_creal_T **pEmxArray
// Return Type  : void
//
void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
	if (*pEmxArray != (emxArray_creal_T *)NULL) {
		if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
			free((void *)(*pEmxArray)->data);
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_creal_T *)NULL;
	}
}

//
// Arguments    : emxArray_int32_T **pEmxArray
// Return Type  : void
//
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
	if (*pEmxArray != (emxArray_int32_T *)NULL) {
		if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
			free((void *)(*pEmxArray)->data);
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_int32_T *)NULL;
	}
}

//
// Arguments    : emxArray_real_T **pEmxArray
// Return Type  : void
//
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
	if (*pEmxArray != (emxArray_real_T *)NULL) {
		if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
			free((void *)(*pEmxArray)->data);
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_real_T *)NULL;
	}
}

//
// Arguments    : emxArray_cell_wrap_0 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int numDimensions)
{
	emxArray_cell_wrap_0 *emxArray;
	int i;
	*pEmxArray = (emxArray_cell_wrap_0 *)malloc(sizeof(emxArray_cell_wrap_0));
	emxArray = *pEmxArray;
	emxArray->data = (cell_wrap_0 *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_cell_wrap_1 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int numDimensions)
{
	emxArray_cell_wrap_1 *emxArray;
	int i;
	*pEmxArray = (emxArray_cell_wrap_1 *)malloc(sizeof(emxArray_cell_wrap_1));
	emxArray = *pEmxArray;
	emxArray->data = (cell_wrap_1 *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_cell_wrap_2 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int numDimensions)
{
	emxArray_cell_wrap_2 *emxArray;
	int i;
	*pEmxArray = (emxArray_cell_wrap_2 *)malloc(sizeof(emxArray_cell_wrap_2));
	emxArray = *pEmxArray;
	emxArray->data = (cell_wrap_2 *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_cell_wrap_3 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int numDimensions)
{
	emxArray_cell_wrap_3 *emxArray;
	int i;
	*pEmxArray = (emxArray_cell_wrap_3 *)malloc(sizeof(emxArray_cell_wrap_3));
	emxArray = *pEmxArray;
	emxArray->data = (cell_wrap_3 *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_creal_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions)
{
	emxArray_creal_T *emxArray;
	int i;
	*pEmxArray = (emxArray_creal_T *)malloc(sizeof(emxArray_creal_T));
	emxArray = *pEmxArray;
	emxArray->data = (creal_T *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_creal_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_creal_T1(emxArray_creal_T **pEmxArray, int numDimensions)
{
	emxArray_creal_T *emxArray;
	int i;
	*pEmxArray = (emxArray_creal_T *)malloc(sizeof(emxArray_creal_T));
	emxArray = *pEmxArray;
	emxArray->data = (creal_T *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_int32_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
	emxArray_int32_T *emxArray;
	int i;
	*pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
	emxArray = *pEmxArray;
	emxArray->data = (int *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_real_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
	emxArray_real_T *emxArray;
	int i;
	*pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
	emxArray = *pEmxArray;
	emxArray->data = (double *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// Arguments    : emxArray_real_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions)
{
	emxArray_real_T *emxArray;
	int i;
	*pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
	emxArray = *pEmxArray;
	emxArray->data = (double *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// File trailer for img_sim_sec_version_emxutil.cpp
//
// [EOF]
//

//end



//img_sim_sec_version_emxAPI.cpp
//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: img_sim_sec_version_emxAPI.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 03-Apr-2019 14:58:18
//

// Include Files
//#include <stdlib.h>
//#include "rt_nonfinite.h"
//#include "img_sim_sec_version.h"
//#include "img_sim_sec_version_emxAPI.h"
//#include "img_sim_sec_version_emxutil.h"

// Function Definitions

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_0 *
//
emxArray_cell_wrap_0 *emxCreateND_cell_wrap_0(int numDimensions, int *size)
{
	emxArray_cell_wrap_0 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_0(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_0 *)calloc((unsigned int)numEl, sizeof(cell_wrap_0));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_1 *
//
emxArray_cell_wrap_1 *emxCreateND_cell_wrap_1(int numDimensions, int *size)
{
	emxArray_cell_wrap_1 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_1(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_1 *)calloc((unsigned int)numEl, sizeof(cell_wrap_1));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_2 *
//
emxArray_cell_wrap_2 *emxCreateND_cell_wrap_2(int numDimensions, int *size)
{
	emxArray_cell_wrap_2 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_2(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_2 *)calloc((unsigned int)numEl, sizeof(cell_wrap_2));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_3 *
//
emxArray_cell_wrap_3 *emxCreateND_cell_wrap_3(int numDimensions, int *size)
{
	emxArray_cell_wrap_3 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_3(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_3 *)calloc((unsigned int)numEl, sizeof(cell_wrap_3));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateND_creal_T(int numDimensions, int *size)
{
	emxArray_creal_T *emx;
	int numEl;
	int i;
	emxInit_creal_T(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (creal_T *)calloc((unsigned int)numEl, sizeof(creal_T));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size)
{
	emxArray_real_T *emx;
	int numEl;
	int i;
	emxInit_real_T(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : cell_wrap_0 *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_0 *
//
emxArray_cell_wrap_0 *emxCreateWrapperND_cell_wrap_0(cell_wrap_0 *data, int
	numDimensions, int *size)
{
	emxArray_cell_wrap_0 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_0(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_1 *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_1 *
//
emxArray_cell_wrap_1 *emxCreateWrapperND_cell_wrap_1(cell_wrap_1 *data, int
	numDimensions, int *size)
{
	emxArray_cell_wrap_1 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_1(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_2 *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_2 *
//
emxArray_cell_wrap_2 *emxCreateWrapperND_cell_wrap_2(cell_wrap_2 *data, int
	numDimensions, int *size)
{
	emxArray_cell_wrap_2 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_2(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_3 *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_cell_wrap_3 *
//
emxArray_cell_wrap_3 *emxCreateWrapperND_cell_wrap_3(cell_wrap_3 *data, int
	numDimensions, int *size)
{
	emxArray_cell_wrap_3 *emx;
	int numEl;
	int i;
	emxInit_cell_wrap_3(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : creal_T *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateWrapperND_creal_T(creal_T *data, int numDimensions,
	int *size)
{
	emxArray_creal_T *emx;
	int numEl;
	int i;
	emxInit_creal_T(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : double *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateWrapperND_real_T(double *data, int numDimensions, int *
	size)
{
	emxArray_real_T *emx;
	int numEl;
	int i;
	emxInit_real_T(&emx, numDimensions);
	numEl = 1;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = numDimensions;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_0 *data
//                int rows
//                int cols
// Return Type  : emxArray_cell_wrap_0 *
//
emxArray_cell_wrap_0 *emxCreateWrapper_cell_wrap_0(cell_wrap_0 *data, int rows,
	int cols)
{
	emxArray_cell_wrap_0 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_0(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_1 *data
//                int rows
//                int cols
// Return Type  : emxArray_cell_wrap_1 *
//
emxArray_cell_wrap_1 *emxCreateWrapper_cell_wrap_1(cell_wrap_1 *data, int rows,
	int cols)
{
	emxArray_cell_wrap_1 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_1(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_2 *data
//                int rows
//                int cols
// Return Type  : emxArray_cell_wrap_2 *
//
emxArray_cell_wrap_2 *emxCreateWrapper_cell_wrap_2(cell_wrap_2 *data, int rows,
	int cols)
{
	emxArray_cell_wrap_2 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_2(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : cell_wrap_3 *data
//                int rows
//                int cols
// Return Type  : emxArray_cell_wrap_3 *
//
emxArray_cell_wrap_3 *emxCreateWrapper_cell_wrap_3(cell_wrap_3 *data, int rows,
	int cols)
{
	emxArray_cell_wrap_3 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_3(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : creal_T *data
//                int rows
//                int cols
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateWrapper_creal_T(creal_T *data, int rows, int cols)
{
	emxArray_creal_T *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_creal_T(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : double *data
//                int rows
//                int cols
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
	emxArray_real_T *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_real_T(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = data;
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	emx->canFreeData = false;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_cell_wrap_0 *
//
emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols)
{
	emxArray_cell_wrap_0 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_0(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_0 *)calloc((unsigned int)numEl, sizeof(cell_wrap_0));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_cell_wrap_1 *
//
emxArray_cell_wrap_1 *emxCreate_cell_wrap_1(int rows, int cols)
{
	emxArray_cell_wrap_1 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_1(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_1 *)calloc((unsigned int)numEl, sizeof(cell_wrap_1));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_cell_wrap_2 *
//
emxArray_cell_wrap_2 *emxCreate_cell_wrap_2(int rows, int cols)
{
	emxArray_cell_wrap_2 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_2(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_2 *)calloc((unsigned int)numEl, sizeof(cell_wrap_2));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_cell_wrap_3 *
//
emxArray_cell_wrap_3 *emxCreate_cell_wrap_3(int rows, int cols)
{
	emxArray_cell_wrap_3 *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_cell_wrap_3(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (cell_wrap_3 *)calloc((unsigned int)numEl, sizeof(cell_wrap_3));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreate_creal_T(int rows, int cols)
{
	emxArray_creal_T *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_creal_T(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (creal_T *)calloc((unsigned int)numEl, sizeof(creal_T));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
	emxArray_real_T *emx;
	int size[2];
	int numEl;
	int i;
	size[0] = rows;
	size[1] = cols;
	emxInit_real_T(&emx, 2);
	numEl = 1;
	for (i = 0; i < 2; i++) {
		numEl *= size[i];
		emx->size[i] = size[i];
	}

	emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
	emx->numDimensions = 2;
	emx->allocatedSize = numEl;
	return emx;
}

//
// Arguments    : emxArray_cell_wrap_0 *emxArray
// Return Type  : void
//
void emxDestroyArray_cell_wrap_0(emxArray_cell_wrap_0 *emxArray)
{
	emxFree_cell_wrap_0(&emxArray);
}

//
// Arguments    : emxArray_cell_wrap_1 *emxArray
// Return Type  : void
//
void emxDestroyArray_cell_wrap_1(emxArray_cell_wrap_1 *emxArray)
{
	emxFree_cell_wrap_1(&emxArray);
}

//
// Arguments    : emxArray_cell_wrap_2 *emxArray
// Return Type  : void
//
void emxDestroyArray_cell_wrap_2(emxArray_cell_wrap_2 *emxArray)
{
	emxFree_cell_wrap_2(&emxArray);
}

//
// Arguments    : emxArray_cell_wrap_3 *emxArray
// Return Type  : void
//
void emxDestroyArray_cell_wrap_3(emxArray_cell_wrap_3 *emxArray)
{
	emxFree_cell_wrap_3(&emxArray);
}

//
// Arguments    : emxArray_creal_T *emxArray
// Return Type  : void
//
void emxDestroyArray_creal_T(emxArray_creal_T *emxArray)
{
	emxFree_creal_T(&emxArray);
}

//
// Arguments    : emxArray_real_T *emxArray
// Return Type  : void
//
void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
	emxFree_real_T(&emxArray);
}

//
// Arguments    : emxArray_cell_wrap_0 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
	numDimensions)
{
	emxInit_cell_wrap_0(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_cell_wrap_1 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int
	numDimensions)
{
	emxInit_cell_wrap_1(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_cell_wrap_2 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int
	numDimensions)
{
	emxInit_cell_wrap_2(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_cell_wrap_3 **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int
	numDimensions)
{
	emxInit_cell_wrap_3(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_creal_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_creal_T(emxArray_creal_T **pEmxArray, int numDimensions)
{
	emxInit_creal_T(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_real_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
	emxInit_real_T(pEmxArray, numDimensions);
}

//
// File trailer for img_sim_sec_version_emxAPI.cpp
//
// [EOF]
//

//end



//
// File trailer for img_sim_sec_version.cpp
//
// [EOF]
//





//***********************************************************************
//***********************************************************************************************************************************************************


// Function Declarations
static void argInit_128x128_creal_T(creal_T result[16384]);
static void argInit_128x128_real_T(double result[16384]);
static cell_wrap_1 argInit_cell_wrap_1();
static void argInit_cell_wrap_2(cell_wrap_2 *result);
static creal_T argInit_creal_T();
static emxArray_cell_wrap_1 *argInit_d25xd25_cell_wrap_1();
static emxArray_cell_wrap_2 *argInit_d25xd25_cell_wrap_2();
static emxArray_creal_T *argInit_d3000xd3000_creal_T();
static emxArray_real_T *argInit_d3000xd3000_real_T();
static double argInit_real_T();
static void main_IMG_grids();
static void main_OTF_grids();
static void main_PSF_grids();
static void main_celling();
static void main_convolution_function();
emxArray_real_T main_final_convol(cv::Mat psf1, cv::Mat psf2, cv::Mat psf3);
static void main_interpImg();
static void main_zone();

// Function Definitions

//
// Arguments    : creal_T result[16384]
// Return Type  : void
//
static void argInit_128x128_creal_T(creal_T result[16384])
{
	int idx0;
	int idx1;

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < 128; idx0++) {
		for (idx1 = 0; idx1 < 128; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result[idx0 + (idx1 << 7)] = argInit_creal_T();
		}
	}
}

//
// Arguments    : double result[16384]
// Return Type  : void
//
static void argInit_128x128_real_T(double result[16384])
{
	int idx0;
	int idx1;

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < 128; idx0++) {
		for (idx1 = 0; idx1 < 128; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result[idx0 + (idx1 << 7)] = argInit_real_T();
		}
	}
}

//
// Arguments    : void
// Return Type  : cell_wrap_1
//
static cell_wrap_1 argInit_cell_wrap_1()
{
	cell_wrap_1 result;

	// Set the value of each structure field.
	// Change this value to the value that the application requires.
	result.f1 = argInit_d3000xd3000_real_T();
	return result;
}

//
// Arguments    : cell_wrap_2 *result
// Return Type  : void
//
static void argInit_cell_wrap_2(cell_wrap_2 *result)
{
	// Set the value of each structure field.
	// Change this value to the value that the application requires.
	argInit_128x128_creal_T(result->f1);
}

//
// Arguments    : void
// Return Type  : creal_T
//
static creal_T argInit_creal_T()
{
	creal_T result;

	// Set the value of the complex variable.
	// Change this value to the value that the application requires.
	result.re = argInit_real_T();
	result.im = argInit_real_T();
	return result;
}

//
// Arguments    : void
// Return Type  : emxArray_cell_wrap_1 *
//
static emxArray_cell_wrap_1 *argInit_d25xd25_cell_wrap_1()
{
	emxArray_cell_wrap_1 *result;
	static int iv2[2] = { 2, 2 };

	int idx0;
	int idx1;

	// Set the size of the array.
	// Change this size to the value that the application requires.
	result = emxCreateND_cell_wrap_1(2, iv2);

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
		for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result->data[idx0 + result->size[0] * idx1] = argInit_cell_wrap_1();
		}
	}

	return result;
}

//
// Arguments    : void
// Return Type  : emxArray_cell_wrap_2 *
//
static emxArray_cell_wrap_2 *argInit_d25xd25_cell_wrap_2()
{
	emxArray_cell_wrap_2 *result;
	static int iv4[2] = { 2, 2 };

	int idx0;
	int idx1;

	// Set the size of the array.
	// Change this size to the value that the application requires.
	result = emxCreateND_cell_wrap_2(2, iv4);

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
		for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			argInit_cell_wrap_2(&result->data[idx0 + result->size[0] * idx1]);
		}
	}

	return result;
}

//
// Arguments    : void
// Return Type  : emxArray_creal_T *
//
static emxArray_creal_T *argInit_d3000xd3000_creal_T()
{
	emxArray_creal_T *result;
	static int iv3[2] = { 2, 2 };

	int idx0;
	int idx1;

	// Set the size of the array.
	// Change this size to the value that the application requires.
	result = emxCreateND_creal_T(2, iv3);

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
		for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result->data[idx0 + result->size[0] * idx1] = argInit_creal_T();
		}
	}

	return result;
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_d3000xd3000_real_T()
{
	emxArray_real_T *result;
	static int iv1[2] = { 2, 2 };

	int idx0;
	int idx1;

	// Set the size of the array.
	// Change this size to the value that the application requires.
	result = emxCreateND_real_T(2, iv1);

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
		for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
		}
	}

	return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
	return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_IMG_grids()
{
	emxArray_real_T *Simulated_IMG;
	emxArray_cell_wrap_1 *image_grids;
	emxInitArray_real_T(&Simulated_IMG, 2);

	// Initialize function 'IMG_grids' input arguments.
	// Initialize function input argument 'image_grids'.
	image_grids = argInit_d25xd25_cell_wrap_1();

	// Call the entry-point 'IMG_grids'.
	IMG_grids(image_grids, argInit_real_T(), Simulated_IMG);
	emxDestroyArray_real_T(Simulated_IMG);
	emxDestroyArray_cell_wrap_1(image_grids);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_OTF_grids()
{
	emxArray_cell_wrap_2 *OTF;
	static creal_T dcv2[16384];
	static creal_T dcv3[16384];
	static creal_T dcv4[16384];
	static creal_T dcv5[16384];
	static creal_T dcv6[16384];
	static creal_T dcv7[16384];
	static creal_T dcv8[16384];
	static creal_T dcv9[16384];
	static creal_T dcv10[16384];
	emxInitArray_cell_wrap_2(&OTF, 2);

	// Initialize function 'OTF_grids' input arguments.
	// Initialize function input argument 'otf1'.
	// Initialize function input argument 'otf3'.
	// Initialize function input argument 'otf5'.
	// Initialize function input argument 'otf11'.
	// Initialize function input argument 'otf13'.
	// Initialize function input argument 'otf15'.
	// Initialize function input argument 'otf21'.
	// Initialize function input argument 'otf23'.
	// Initialize function input argument 'otf25'.
	// Call the entry-point 'OTF_grids'.
	argInit_128x128_creal_T(dcv2);
	argInit_128x128_creal_T(dcv3);
	argInit_128x128_creal_T(dcv4);
	argInit_128x128_creal_T(dcv5);
	argInit_128x128_creal_T(dcv6);
	argInit_128x128_creal_T(dcv7);
	argInit_128x128_creal_T(dcv8);
	argInit_128x128_creal_T(dcv9);
	argInit_128x128_creal_T(dcv10);
	OTF_grids(argInit_real_T(), dcv2, dcv3, dcv4, dcv5, dcv6, dcv7, dcv8, dcv9,
		dcv10, OTF);
	emxDestroyArray_cell_wrap_2(OTF);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_PSF_grids()
{
	emxArray_cell_wrap_3 *PSF_final;
	emxArray_cell_wrap_2 *OTF;
	double PSF_grid_factor;
	double img_ht_x;
	emxArray_real_T *imageArray;
	emxInitArray_cell_wrap_3(&PSF_final, 2);

	// Initialize function 'PSF_grids' input arguments.
	// Initialize function input argument 'OTF'.
	OTF = argInit_d25xd25_cell_wrap_2();
	PSF_grid_factor = argInit_real_T();
	img_ht_x = argInit_real_T();

	// Initialize function input argument 'imageArray'.
	imageArray = argInit_d3000xd3000_real_T();

	// Call the entry-point 'PSF_grids'.
	PSF_grids(OTF, PSF_grid_factor, img_ht_x, imageArray, argInit_real_T(),
		PSF_final);
	emxDestroyArray_cell_wrap_3(PSF_final);
	emxDestroyArray_real_T(imageArray);
	emxDestroyArray_cell_wrap_2(OTF);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_celling()
{
	emxArray_cell_wrap_0 *M;
	emxArray_real_T *imageArray;
	emxInitArray_cell_wrap_0(&M, 2);

	// Initialize function 'celling' input arguments.
	// Initialize function input argument 'imageArray'.
	imageArray = argInit_d3000xd3000_real_T();

	// Call the entry-point 'celling'.
	celling(imageArray, argInit_real_T(), M);
	emxDestroyArray_cell_wrap_0(M);
	emxDestroyArray_real_T(imageArray);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_convolution_function()
{
	emxArray_cell_wrap_0 *IMG;
	emxArray_cell_wrap_1 *M;
	emxArray_cell_wrap_1 *PSF;
	emxInitArray_cell_wrap_0(&IMG, 2);

	// Initialize function 'convolution_function' input arguments.
	// Initialize function input argument 'M'.
	M = argInit_d25xd25_cell_wrap_1();

	// Initialize function input argument 'PSF'.
	PSF = argInit_d25xd25_cell_wrap_1();

	// Call the entry-point 'convolution_function'.
	convolution_function(M, PSF, argInit_real_T(), IMG);
	emxDestroyArray_cell_wrap_0(IMG);
	emxDestroyArray_cell_wrap_1(PSF);
	emxDestroyArray_cell_wrap_1(M);
}

//
// Arguments    : void
// Return Type  : emxArray_real_T
//
emxArray_real_T main_final_convol(cv::Mat PSF2, cv::Mat PSF3, cv::Mat PSF5, real magnification, real rmsRadius)
{
	emxArray_real_T *Simulated_IMG;
	//emxArray_real_T *imageArray;
	static double dv4[16384];
	static double dv5[16384];
	static double dv6[16384];
	emxInitArray_real_T(&Simulated_IMG, 2);

	// Initialize function 'final_convol' input arguments.
	// Initialize function input argument 'imageArray'.
	//imageArray = argInit_d3000xd3000_real_T();

		//using sopt diagrat get size of spot
	// TODO change to rmsRadius
	double rms = 0.1;//from previous calcuation on open cv
	double Mag = magnification;//from previous calcuation on open cv
	double obj_semi_ht_x = 2;//user given
	double obj_semi_ht_y = 2;//user given
	// Carsten: increase max size is 20
	double siz = 10;



	double img_ht_x = Mag * obj_semi_ht_x;
	double img_ht_y = Mag * obj_semi_ht_y;
	//ask user for sampling of PSF modelling
	//user given example 3x3, 4x4, 5x5, 6x6, 7x7, 8x8, ..etc
	double PSF_grid_factor = siz;
	//searching coordinates to compute psf using ray tracing
	double ex_psf_pt_x = img_ht_x - (img_ht_x / PSF_grid_factor);
	double ex_psf_pt_y = img_ht_y - (img_ht_y / PSF_grid_factor);
	//coordinates = (0,0), (0, ex_psf_pt_y), (ex_psf_pt_x, ex_psf_pt_y)

	cv::Mat IMG = cv::imread("elefant_sharp_gray_symetric_small.png", CV_LOAD_IMAGE_GRAYSCALE);
	cv::imshow("gray loaded", IMG);
	cv::waitKey(0);
	cv::Mat IMG_double;
	IMG.convertTo(IMG_double, CV_64F);
	cv::imshow("converted", IMG_double);
	cv::waitKey(0);

	emxArray_real_T* imageArray;
	emxInit_real_T(&imageArray, 2);


	imageArray->size[0] = IMG_double.rows;
	imageArray->size[1] = IMG_double.cols;
	imageArray->numDimensions = 2;
	imageArray->allocatedSize = IMG_double.rows * IMG_double.cols;
	imageArray->canFreeData = false;
	double* data_ptr = (double*)IMG_double.data;
	imageArray->data = data_ptr;

	//_________________
	// to test it

	int rows = imageArray->size[0];
	int cols = imageArray->size[1];
	uchar* data_ptr_test = (uchar*)imageArray->data;
	cv::Mat Sim_IMG_test(rows, cols, CV_64FC1, data_ptr_test);


	cv::imshow("test", Sim_IMG_test);
	cv::waitKey(0);

	//_________________


	using namespace std;



	double psf2[16384];
	for (int i = 0; i < 16384; i++)
	{
		int j = i % 128;
		int k = i / 128;
		psf2[i] = PSF2.at<double>(j, k);
	}


	double psf3[16384];
	for (int i = 0; i < 16384; i++)
	{
		int j = i % 128;
		int k = i / 128;
		psf3[i] = PSF3.at<double>(j, k);
	}



	double psf5[16384];
	for (int i = 0; i < 16384; i++)
	{
		int j = i % 128;
		int k = i / 128;
		psf5[i] = PSF5.at<double>(j, k);
	}




	// Call the entry-point 'final_convol'.
	//argInit_128x128_real_T(dv4);
	//argInit_128x128_real_T(dv5);
	//argInit_128x128_real_T(dv6);
	final_convol(imageArray, PSF_grid_factor, img_ht_x, rms,
		psf2, psf3, psf5, Simulated_IMG);
	//emxDestroyArray_real_T(Simulated_IMG);
	//emxDestroyArray_real_T(imageArray);


	return *Simulated_IMG;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_interpImg()
{
	emxArray_creal_T *out;
	emxArray_creal_T *im;
	emxInitArray_creal_T(&out, 2);

	// Initialize function 'interpImg' input arguments.
	// Initialize function input argument 'im'.
	im = argInit_d3000xd3000_creal_T();

	// Call the entry-point 'interpImg'.
	interpImg(im, argInit_real_T(), out);
	emxDestroyArray_creal_T(out);
	emxDestroyArray_creal_T(im);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_zone()
{
	emxArray_real_T *f;
	emxArray_real_T *Obj;
	emxInitArray_real_T(&f, 2);

	// Initialize function 'zone' input arguments.
	// Initialize function input argument 'Obj'.
	Obj = argInit_d3000xd3000_real_T();

	// Call the entry-point 'zone'.
	zone(Obj, argInit_real_T(), argInit_real_T(), argInit_real_T(), argInit_real_T
	(), f);
	emxDestroyArray_real_T(f);
	emxDestroyArray_real_T(Obj);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main_im()
{
	// Initialize the application.
	// You do not need to do this more than one time.
	//img_sim_sec_version_initialize();

	// Invoke the entry-point functions.
	// You can call entry-point functions multiple times.
	/*main_celling();
	main_convolution_function();
	main_final_convol();
	main_IMG_grids();
	main_interpImg();
	main_OTF_grids();
	main_PSF_grids();
	main_zone();*/
	//////////////////////////////////////////////////////////////

	//emxArray_real_T *Simulated_IMG;

	//*Simulated_IMG = main_final_convol();



	////////////////////////////////////////////////////////////////
	// Terminate the application.
	// You do not need to do this more than one time.
	//img_sim_sec_version_terminate();
	return 0;
}
// get Simulated Image
cv::Mat ImageSimulation::getSimulatedImage()
{

	return mImageSimulation;
}


cv::Mat ImageSimulation::ImgSimMain()
{
	img_sim_sec_version_initialize();

	//cv::Mat IMG = cv::imread("ear.jpg", CV_LOAD_IMAGE_COLOR);
	/*cv::Mat IMG = cv::imread("gray.jpeg", CV_LOAD_IMAGE_GRAYSCALE);   //chech conversion of CV MAT to emxArray_real_T
	int sizeImagecols = IMG.cols;
	int sizeImagerows = IMG.rows;*/

	//emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);


	emxArray_real_T *Simulated_IMG;
	emxInit_real_T(&Simulated_IMG, 2);


	*Simulated_IMG = main_final_convol(mPSF_1, mPSF_2, mPSF_3, mMagnification, mRMSradius);


	int rows = Simulated_IMG->size[0];
	int cols = Simulated_IMG->size[1];
	uchar* data_ptr = (uchar*)Simulated_IMG->data;
	cv::Mat Sim_IMG(rows, cols, CV_64FC1, data_ptr);

	double min, max;
	cv::minMaxLoc(Sim_IMG, &min, &max);



	cv::imshow("Simulated Image", Sim_IMG);
	cv::imwrite("elefant_simulated_gray_symetric_small.png", 255 * Sim_IMG / max);
	cv::waitKey(0);



	mImageSimulation = Sim_IMG;
	img_sim_sec_version_terminate();

	return mImageSimulation;
}

