#pragma once

#include <vector>

class Statistik
{
 public:
  float mean(std::vector<float> data, int maxnr);
  float max(std::vector<float> data, int max);

  float min(std::vector<float> data, int max);

  void histogram(std::vector<float> data, int max, int bins, float deltabin, float start);
  float sdev(std::vector<float> data, int max);
  double mean(std::vector<double> data, int max);
  double sdev(std::vector<double> data, int max);
  float correlation(std::vector<float> datax, std::vector<float> datay, int anzahl);

private:
  float mMean;
  float mSdev;

};

