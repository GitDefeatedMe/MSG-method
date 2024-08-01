#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>

class Vector
{
public:
	Vector(int size = 10)
	{
		data.resize(size);
		std::fill(data.begin(), data.end(), 0.);
	}
	Vector(const Vector& v)
	{
		data = v.data;
	}
	~Vector() {}
	Vector& operator = (const Vector& v)
	{
		data = v.data;
		return *this;
	}
	Vector operator - (Vector& right)
	{
		Vector result((int)data.size());
		for (int i = 0; i < (int)data.size(); i++)
		{
			result[i] = data[i] - right.data[i];
		}
		return result;
	}
	Vector operator - (Vector right)
	{
		Vector result((int)data.size());
		for (int i = 0; i < (int)data.size(); i++)
		{
			result[i] = data[i] - right.data[i];
		}
		return result;
	}
	Vector operator + (Vector& right)
	{
		Vector result((int)data.size());
		for (int i = 0; i < (int)data.size(); i++)
		{
			result[i] = data[i] + right.data[i];
		}
		return result;
	}
	Vector operator + (Vector right)
	{
		Vector result((int)data.size());
		for (int i = 0; i < (int)data.size(); i++)
		{
			result[i] = data[i] + right.data[i];
		}
		return result;
	}
	Vector operator * (double right)
	{
		Vector result((int)data.size());
		for (size_t i = 0; i < data.size(); i++)
		{
			result[i] = data[i] * right;
		}
		return result;
	}
	double operator * (Vector right)
	{
		double result = 0;
		for (size_t i = 0; i < data.size(); i++)
		{
			result += data[i] * right.data[i];
		}
		return result;
	}
	Vector operator -()
	{
		Vector result((int)data.size());
		for (size_t i = 0; i < data.size(); i++)
			result.data[i] = -data[i];
		return result;
	}
	void Resize(int size)
	{
		int oldSize = (int)data.size();
		data.resize(size);
		for (int i = oldSize; i < size; i++)
			data[i] = 0;
	}
	void Print()
	{
		for (int i = 0; i < (int)data.size(); i++)
			std::cout << data[i] << '\t';
		std::cout << '\n';
	}
	void PrintCol()
	{
		for (int i = 0; i < (int)data.size(); i++)
			std::cout << data[i] << '\n';
	}
	int GetSize()
	{
		return (int)data.size();
	}
	double& operator[] (const int ind)
	{
		return data[ind];
	}
	double Norm()
	{
		double res = 0.;
		for (size_t i = 0; i < data.size(); i++)
		{
			res += data[i] * data[i];
		}
		return sqrt(res);
	}
	double NormMax()
	{
		double res = 0.;
		for (size_t i = 0; i < data.size(); i++)
		{
			if (abs(data[i]) > res)
				res = abs(data[i]);
		}
		return res;
	}
	int indNormMax()
	{
		int ind = 0;
		double res = 0.;
		for (size_t i = 0; i < data.size(); i++)
		{
			if (abs(data[i]) > res)
			{
				res = abs(data[i]);
				ind = i;
			}
		}
		return ind;
	}

	double MultiplyThread (Vector right, int threads)
	{
		std::vector<double> results(threads);
		std::vector<std::thread> ths;

		for (int i = 0; i < threads; i++)
		{
			results[i] = 0;
		}

		for (int indT = 0; indT < threads; indT++)
		{
			ths.push_back(std::thread([this, &right, &results, indT, threads]()
				{
					for (int i = (int)data.size() * indT / threads; i < (int)data.size() * (indT + 1) / threads; i++)
					{
						results[indT] += data[i] * right.data[i];
					}
				}));
		}

		for (auto it = ths.begin(); it != ths.end(); it++)
			it->join();

		double result = 0;
		for (int i = 0; i < threads; i++)
		{
			result += results[i];
		}
		return result;
	}
private:
	std::vector<double> data;
};

double Scalar(Vector left, Vector right)
{
	double res = 0;
	for (int i = 0; i < left.GetSize(); i++)
	{
		res += left[i] * right[i];
	}
	return res;
}

class AbstractMatrix
{
public:
	AbstractMatrix(int N, int M, double a, double b, double c, double d)
	{
		this->N = N;
		this->M = M;
		this->a = a; this->b = b;
		this->c = c; this->d = d;

		h = (b - a) / (double)N;
		k = (d - c) / (double)M;

		h2 = 1. / (h * h);
		k2 = 1. / (k * k);

		A = -2. * (h2 + k2);
	}
	AbstractMatrix(const AbstractMatrix& matrix)
	{
		N = matrix.N;
		M = matrix.M;
		a = matrix.a; b = matrix.b;
		c = matrix.c; d = matrix.d;

		h = matrix.h;
		k = matrix.k;

		h2 = matrix.h2;
		k2 = matrix.k2;

		A = matrix.A;
	}
	AbstractMatrix& operator = (const AbstractMatrix& matrix)
	{
		N = matrix.N;
		M = matrix.M;
		a = matrix.a; b = matrix.b;
		c = matrix.c; d = matrix.d;

		h = matrix.h;
		k = matrix.k;

		h2 = matrix.h2;
		k2 = matrix.k2;

		A = matrix.A;

		return *this;
	}
	~AbstractMatrix() {}

	void Print()
	{
		std::vector<Elem> data(5);
		size_t draw = 0;

		for (int matrixX = 0; matrixX < (N - 1) * (M - 1); matrixX++)
		{
			draw = 0;
			int j = matrixX / (N - 1);
			int i = matrixX % (N - 1);

			if (i  >= N / 2 && i  < N - 1 && j < M / 2)
			{
				if (matrixX - (N - 1) > 0)
				{
					data[draw].val = k2;
					data[draw++].pos = matrixX - (N - 1);
				}
				if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1) && i != N / 2)
				{
					data[draw].val = h2;
					data[draw++].pos = matrixX - 1;
				}
				data[draw].val = A;
				data[draw++].pos = matrixX;
				if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
				{
					data[draw].val = h2;
					data[draw++].pos = matrixX + 1;
				}
				if (matrixX + (N - 1) < (N - 1) * (M - 1))
				{
					data[draw].val = k2;
					data[draw++].pos = matrixX + (N - 1);
				}
			}
			else if (i < (N - 1) && j >= M / 2 && j < (M - 1))
			{
				if (matrixX - (N - 1) > 0 && !(j == M / 2 && i < N / 2))
				{
					data[draw].val = k2;
					data[draw++].pos = matrixX - (N - 1);
				}
				if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1))
				{
					data[draw].val = h2;
					data[draw++].pos = matrixX - 1;
				}
				data[draw].val = A;
				data[draw++].pos = matrixX;
				if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
				{
					data[draw].val = h2;
					data[draw++].pos = matrixX + 1;
				}
				if (matrixX + (N - 1) < (N - 1) * (M - 1))
				{
					data[draw].val = k2;
					data[draw++].pos = matrixX + (N - 1);

				}
			}


			int p = 0;
			for (int k = 0; k < (N - 1) * (M - 1); k++)
			{
				if (p < draw && data[p].pos == k)
				{
					std::cout << data[p++].val << "\t";
				}
				else
					std::cout << "0\t";
			}
			std::cout << '\n';
		}
	}
	Vector operator * (Vector v)
	{
		Vector result((N-1)*(M-1));

		int i, j, matrixX;

		for (int matrixX = 0; matrixX < v.GetSize(); matrixX++)
		{
			j = matrixX / (N - 1);
			i = matrixX % (N - 1);


			if (i >= N / 2 && i < N - 1 && j < M / 2)
			{
				result[matrixX] = A * v[matrixX];

				if (matrixX - (N - 1) > 0)
				{
					result[matrixX] += k2 * v[matrixX - (N - 1)];
				}
				if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1) && i != N / 2)
				{
					result[matrixX] += h2 * v[matrixX - 1];
				}
				if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
				{
					result[matrixX] += h2 * v[matrixX + 1];
				}
				if (matrixX + (N - 1) < (N - 1) * (M - 1))
				{
					result[matrixX] += k2 * v[matrixX + (N - 1)];
				}
			}
			else if (i < (N - 1) && j >= M / 2 && j < (M - 1))
			{

				result[matrixX] = A * v[matrixX];

				if (matrixX - (N - 1) > 0 && !(j == M / 2 && i < N / 2))
				{
					result[matrixX] += k2 * v[matrixX - (N - 1)];
				}
				if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1))
				{
					result[matrixX] += h2 * v[matrixX - 1];
				}
				if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
				{
					result[matrixX] += h2 * v[matrixX + 1];
				}
				if (matrixX + (N - 1) < (N - 1) * (M - 1))
				{
					result[matrixX] += k2 * v[matrixX + (N - 1)];
				}
			}
		}

		return result;
	}

	Vector MultyplyThreading (Vector v, int threads)
	{
		Vector result((N - 1) * (M - 1));
		std::vector<std::thread> ths;

		for (int indT = 0; indT < threads; indT++)
		{
			ths.push_back(std::thread([this, &v, &result, indT, threads]()
				{
					double vecVal;
					int i, j, matrixX;

					for (int matrixX = v.GetSize() * indT / threads; matrixX < v.GetSize() * (indT + 1) / threads; matrixX++)
					{
						j = matrixX / (N - 1);
						i = matrixX % (N - 1);

						if (i >= N / 2 && i < N - 1 && j < M / 2)
						{
							result[matrixX] = A * v[matrixX];

							if (matrixX - (N - 1) > 0)
							{
								result[matrixX] += k2 * v[matrixX - (N - 1)];
							}
							if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1) && i != N / 2)
							{
								result[matrixX] += h2 * v[matrixX - 1];
							}
							if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX + 1];
							}
							if (matrixX + (N - 1) < (N - 1) * (M - 1))
							{
								result[matrixX] += k2 * v[matrixX + (N - 1)];
							}
						}
						else if (i < (N - 1) && j >= M / 2 && j < (M - 1))
						{

							result[matrixX] = A * v[matrixX];

							if (matrixX - (N - 1) > 0 && !(j == M / 2 && i < N / 2))
							{
								result[matrixX] += k2 * v[matrixX - (N - 1)];
							}
							if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX - 1];
							}
							if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX + 1];
							}
							if (matrixX + (N - 1) < (N - 1) * (M - 1))
							{
								result[matrixX] += k2 * v[matrixX + (N - 1)];
							}
						}
					}
				}));
		}

		for (auto it = ths.begin(); it != ths.end(); it++)
			it->join();

		return result;
	}
	Vector ResidualThreading(Vector v, Vector b,int threads)
	{
		Vector result((N - 1) * (M - 1));
		std::vector<std::thread> ths;
		for (int indT = 0; indT < threads; indT++)
		{
			ths.push_back(std::thread([this, &v, &result, indT, threads, &b]()
				{
					
					double vecVal;
					int i, j, matrixX;

					for (int matrixX = v.GetSize() * indT / threads; matrixX < v.GetSize() * (indT + 1) / threads; matrixX++)
					{
						j = matrixX / (N - 1);
						i = matrixX % (N - 1);

						if (i >= N / 2 && i < N - 1 && j < M / 2)
						{
							result[matrixX] = A * v[matrixX] - b[matrixX];

							if (matrixX - (N - 1) > 0)
							{
								result[matrixX] += k2 * v[matrixX - (N - 1)];
							}
							if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1) && i != N / 2)
							{
								result[matrixX] += h2 * v[matrixX - 1];
							}
							if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX + 1];
							}
							if (matrixX + (N - 1) < (N - 1) * (M - 1))
							{
								result[matrixX] += k2 * v[matrixX + (N - 1)];
							}
						}
						else if (i < (N - 1) && j >= M / 2 && j < (M - 1))
						{

							result[matrixX] = A * v[matrixX] - b[matrixX];

							if (matrixX - (N - 1) > 0 && !(j == M / 2 && i < N / 2))
							{
								result[matrixX] += k2 * v[matrixX - (N - 1)];
							}
							if (matrixX - 1 > 0 && (matrixX - 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX - 1];
							}
							if (matrixX + 1 < (N - 1) * (M - 1) && (matrixX + 1) / (N - 1) == matrixX / (N - 1))
							{
								result[matrixX] += h2 * v[matrixX + 1];
							}
							if (matrixX + (N - 1) < (N - 1) * (M - 1))
							{
								result[matrixX] += k2 * v[matrixX + (N - 1)];
							}
						}
					}
				}));
		}

		for (auto it = ths.begin(); it != ths.end(); it++)
			it->join();

		return result;
	}
	
private:
	int N, M;
	double a, b, c, d;
	double h, k, h2, k2;
	double A;

	struct Elem
	{
		double val;
		int pos;
	};

};