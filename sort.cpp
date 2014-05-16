
// 
// Comparison of the performance between sliding median algs
// 

#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<numeric>

class Pos{
public:
	Pos(int max_val){
		max = max_val;
		p = 0;
	}
	~Pos(){}
	
	void operator++(int){
		p++;
		if (p == max) p = 0;
	}
	int get_val(void){
		return p;
	}
private:
	int max;
	int p;
};

class SortedStorage{
public:
	SortedStorage(){}
	~SortedStorage(){}

	void init(std::vector<double>& initial_dat){
		len = initial_dat.size();
		sorted = initial_dat;
		unsorted = initial_dat;
		for(int i = 0; i < len; i++){
			key.push_back(i);
		}
		sort(sorted.begin(), sorted.end());
	}

	void push(double new_dat){
		int p_pos = find(key.begin(), key.end(), 0) - key.begin();
		for(int i = p_pos; i < len; i++){
			sorted[i] = sorted[i+1];
			key[i] = key[i+1];
		}
		for(int i = 0; i < len - 1; i++)
			key[i] --;

		int new_p = 0;
		for(int i = 0; i < len - 1; i++){
			if(sorted[i] <= new_dat && new_dat <= sorted[i + 1]){
				new_p = i + 1;
				break;
			}
		}
		// insert
		for(int i = len - 1; i >= new_p + 1; i--){
			sorted[i] = sorted [i-1];
			key[i] = key [i-1];
		}
		sorted[new_p] = new_dat;
		key[new_p] = len - 1;
	}

	double get_median(void){
		return sorted[len/2];
	}

	void cpy(std::vector<double> tmp){
		unsorted = tmp;
	}
	double calc_median(void){
		sort(unsorted.begin(), unsorted.end());
		return unsorted[len/2];
	}

	void print_list(void){
		for(int i = 0; i < len; i++){
			std::cout << sorted [i] << " ";;
		}
		std::cout << "\n";
		for(int i = 0; i < len; i++){
			std::cout << key [i] << " ";;
		}
		std::cout << "\n";
	}
	
private:
	std::vector<double> sorted;
	std::vector<double> unsorted;
	std::vector<int> key;
	int len;
};


class MovingAverage{
public:
	MovingAverage() : p(NULL){}
	~MovingAverage(){
		delete p;
		p = NULL;
	}

	void init(std::vector<double>& initial_dat){
		lst = initial_dat;
		p = new Pos(lst.size());
		sum = accumulate(lst.begin(), lst.end(), 0);
	}

	void push(double new_dat){
		sum -= lst[p->get_val()];
		sum += new_dat;
		lst[p->get_val()] = new_dat;
		(*p)++;
	}

	double get_mean(void){
		return sum;
	}

	double calc_mean(void){
		return accumulate(lst.begin(), lst.end(), 0.);
	}

	void print_list(void){
		for(int i = 0; i < lst.size(); i++){
			std::cout << lst [i] << " ";;
		}
		std::cout << "\n";
	}
	
private:
	std::vector<double> lst;
	Pos *p;
	double sum;
};

int main(void){
	std::vector<double> a;
	int N = 17;
	for(int i = 0; i < N; i++){
		a.push_back(30*sin(i * 2));
	}	
	SortedStorage s;
	MovingAverage m;
	s.init(a);
	m.init(a);

	std::cout << s.get_median() << std::endl;
	std::cout << m.get_mean()/a.size() << std::endl;

//-----------------------------------------------------------------------------------------------
	for(int i = 0; i < 30; i++){
		s.push((i *2 + 1));
//		s.print_list();
		std::cout << s.get_median() << std::endl;
	}
	std::cerr << "modified version done" << std::endl;

	for(int i = 0; i < 30; i++){
		m.push((i *2 + 1));
//		m.print_list();
		std::cout << m.get_mean()/a.size() << std::endl;
	}
	std::cerr << "moving average done" << std::endl;




	double aaa = 0;
	for(int i = 0; i < 10000000*3; i++){
		s.push(10 * sin (i *2 + 1));
//		s.print_list();
		if(i % 1000000 == 0)
			std::cout << s.get_median() << std::endl;
	}
		std::cout << s.get_median() << std::endl;
	std::cerr << "modified version done" << std::endl;

	for(int i = 0; i < 10000000*3; i++){
//		s.push(10 * sin (i *2 + 1));
//		s.print_list();
		std::vector<double> tmp (N);
		s.cpy(tmp);
		double a = s.calc_median();
		aaa += a;
		if(i % 1000000 == 0)
			std::cout << s.get_median() << std::endl;
	}
		std::cout << s.get_median() << std::endl;
	std::cerr << "modified version done" << std::endl;

	for(int i = 0; i < 10000000*3; i++){
		m.push(10 * sin(i *2 + 1));
//		m.print_list();
		double a = m.get_mean();
		aaa += a;
		if(i % 1000000 == 0)
			std::cout << s.get_median() << std::endl;
	}
		std::cout << m.get_mean()/a.size() << std::endl;
	std::cerr << "moving average done" << std::endl;

	for(int i = 0; i < 10000000*3; i++){
		m.push(10 * sin(i *2 + 1));
//		m.print_list();
		double a = m.calc_mean();
		aaa += a;
		if(i % 1000000 == 0)
			std::cout << s.get_median() << std::endl;
	}
	std::cout << m.calc_mean()/a.size() << std::endl;
	std::cerr << "moving average done" << std::endl;
	std::cout << aaa << std::endl;

	return 0;
}

