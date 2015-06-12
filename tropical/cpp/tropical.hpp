
#include<string>
#include<sstream>

class Tropical{
public:
	Tropical(){
		val = 0;
		infty_flag = false;
	}
	Tropical(double x){
		val = x; 
		infty_flag = false;
	}
	Tropical(const char* x){
		if(x[0] == '0'){
			infty_flag = true;
			val = -10000000000;
		}
	}
	
	Tropical operator=(double rhs){
		return Tropical(rhs);
	}

	Tropical operator+=(const Tropical& rhs){
		*this = this->infty_flag 
					? rhs.infty_flag 
						? Tropical("0") 
						: rhs.val 
					: ((this->val > rhs.val) 
							? *this 
							: rhs);
		return *this;
	}
	
	Tropical operator*=(const Tropical& rhs){
		*this = (this->infty_flag || rhs.infty_flag) 
					? Tropical("0") 
					: Tropical(this->val + rhs.val);
		return *this;
	}

	double val;

	std::string show_value(){
		if (!infty_flag){
			std::stringstream ss;
			ss << val;
			return ss.str();
		}else{
			return std::string("-infty");
		}
	}
private:
	bool infty_flag;
};

Tropical operator+(const Tropical& lhs, const Tropical &rhs){
	Tropical tmp = lhs;
	return tmp += rhs;
}

Tropical operator*(const Tropical& lhs, const Tropical &rhs){
	Tropical tmp = lhs;
	return tmp *= rhs;
}

