#include "statistik.h"
#define INVALID -1e20
#include <math.h>
#include <iostream>
// ./esaAcrossSlitRectangle ~/ESA2017/02325-1_66502/stichedEdgeProcessed.pgm 80 163 > c


float Statistik::max(std::vector<float> data, int max)
{
	float maxi = data[0];
	for (int t = 0; t < max; t++)
		if (data[t] > maxi)
			maxi = data[t];
	return maxi;
}

float Statistik::min(std::vector<float> data, int max)
{
	float mini = data[0];
	for (int t = 0; t < max; t++)
		if (data[t] < mini)
			mini = data[t];
	return mini;
}

float Statistik::correlation(std::vector<float> datax, std::vector<float> datay, int anzahl)
{
  int count = 0;
  double meanx = 0;
  double meany = 0;

  for(int t=0; t < anzahl; t++)
    {
      if(datay[t] > INVALID && datax[t] > INVALID)
	  {
	    meanx += datax[t];
	    meany += datay[t];
	    count++;
	  }
    }

  meanx /= count;
  meany /= count;

  double z = 0;
  double n1 = 0;
  double n2 = 0;
  float x,y;

  for(int t=0; t < anzahl; t++)
    {
      if(datay[t] > INVALID && datax[t] > INVALID)
	{
	  x = datax[t];
	  y = datay[t];
	  z += (x-meanx) * (y-meany);
	  n1 +=(x-meanx) * (x-meanx);
	  n2 +=(y-meany) * (y-meany);
	  //	  cerr << z << "  " << n1 << "  " << n2 << endl;
	}
    }

  return z/sqrt(n1 * n2);
}


//////////////////////////////////////////////////////////////////////
void Statistik::histogram(std::vector<float> data, int maxnr, int bins, float deltabin, float start)
{
  static float histo[1000];
  bool done[1000];
  
  for(int t=0; t < bins; t++)
    {
      histo[t] = 0;
      done[t] = false;
    }

  for(int t=0; t < maxnr; t++)

    if(data[t] < start && done[t] == false)
      {
	histo[0]++;
	done[t] = true;
      }
  //  std::cout << " ----------- " << histo[0] << "  " << start << std::endl;

  int cnt = 0;
  while(cnt < bins)
    {
      for(int t=0; t < maxnr; t++)
	if(data[t] < start+cnt*deltabin && done[t] == false)
	  {
	    histo[cnt]++;
	    done[t] = true;
	  }
      cnt++;
    }

  // Beachte: Ausgegeben wird als x der Mittelpunkt des Bins
  for(int t=0; t < bins; t++)
    std::cout << start + t*deltabin - deltabin/2<< "  " << histo[t] << std::endl;

#if 0 // Nur zum Gegencheck
  cnt = 0;
  for(int t=0; t < maxnr; t++)
    if(data[t] < 1.5)
      cnt++;
  std::cout << cnt << std::endl;
#endif
  // ausgabe -3.5 10 bedeutet, dass 10 im bin -4 ... -3 drin sind.
}
//////////////////////////////////////////////////////////////////////
double Statistik::mean(std::vector<double> data, int maxnr)
{
  double sum = 0;
  int count = 0;
  for(int t=0; t < maxnr; t++)
    {
      if(data[t] > INVALID)
	{
	  sum += data[t];
	  count++;
	}
    }
  mMean = sum/count;
  return mMean;
}


//////////////////////////////////////////////////////////////////////
float Statistik::mean(std::vector<float> data, int maxnr)
{
  double sum = 0;
  int count = 0;
  for(int t=0; t < maxnr; t++)
    {
      if(data[t] > INVALID)
	{
	  sum += data[t];
	  count++;
	}
    }
  mMean = sum/count;
  return mMean;
}

////////////////////////////////////////////////////////////

float Statistik::sdev(std::vector<float> data, int maxnr)
{
  mean(data, maxnr);

  double sum = 0;
  int count = 0;
  for(int t=0; t < maxnr; t++)
    {
      if(data[t] > INVALID)
	{
	  double diff = data[t] - mMean;
	  sum += diff*diff;
	  count++;
	}
    }
  mSdev = sqrt(sum/count);
  return mSdev;
}


////////////////////////////////////////////////////////////

double Statistik::sdev(std::vector<double> data, int maxnr)
{
  mean(data, maxnr);

  double sum = 0;
  int count = 0;
  for(int t=0; t < maxnr; t++)
    {
      if(data[t] > INVALID)
	{
	  double diff = data[t] - mMean;
	  sum += diff*diff;
	  count++;
	}
    }
  mSdev = sqrt(sum/count);
  return mSdev;
}
