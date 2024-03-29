#include "Ray.h"


Ray::Ray(){
	d = vector<float>(4,0);
	p = vector<float>(4,0);
	d[3] = p[3] = 1;
}

Ray::Ray(vector<float> d, vector<float> p){
	this->d = d;
	this->p = p;
	a = b = c = 0;
	for(int i=0; i<3; ++i){
		a += d[i] * d[i];
		b += p[i] * d[i];
		c += p[i] * p[i];
	}
}

// Ray Ray::multiply(Matrix &m, bool inverse){
// 	Ray r (	
// 		inverse ? m.Inv_Vec_Mul(this->d) : m.Vec_Mul(this->d),
// 		inverse ? m.Inv_Vec_Mul(this->p) : m.Vec_Mul(this->p)
// 	);
// 	return r;
// }

void Ray::set_d(vector<float> d){
	a = b = 0;
	for(int i=0; i<3; ++i){
		this->d[i] = d[i];
		a += d[i] * d[i];
		b += p[i] * d[i];
		// c += p[i] * p[i];
	}
}

void Ray::set_p(vector<float> p){
	b = c = 0;
	for(int i=0; i<3; ++i){
		this->p[i] = p[i];
		// a += d[i] * d[i];
		b += p[i] * d[i];
		c += p[i] * p[i];
	}
}

std::tuple<float, float, float> Ray::get_abc(){
	return std::make_tuple(a,b,c);
}

vector<float> Ray::get_point(float t){
	vector<float> ret(4,1);
	for(int i=0; i<3; ++i){
		ret[i] = p[i] + t*d[i];
	}
	return ret;
}

void Ray::add_offset(vector<float> &o)
{
	b = c = 0;
	for (int i = 0; i < 3; i++)
	{
		p[i] += o[i];
		b += p[i]*d[i];
		c += p[i]*p[i];
	}
}

void Ray::add_dirn(vector<float> &dn)
{
	a = b = 0;
	for (int i = 0; i < 3; i++)
	{
		d[i] += dn[i];
		a += d[i]*d[i];
		b += p[i]*d[i];
	}
}

void Ray::print(){
	cout << "d "; for(auto i : d) cout << i << " "; cout << endl;
	cout << "p "; for(auto i : p) cout << i << " "; cout << endl;
	// cout << "a " << a << " b " << b << " c " << c << endl;
}