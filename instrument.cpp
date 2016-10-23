#include <iostream> 
using namespace std; 


class I{
	public:
//		virtual void play() const = 0; 
//		virtual void play() const{cout << "I::play" << endl;}
		void play() const{cout << "I::play" << endl;}

};

class W: public I{
	public:
		void play() const{cout << "W::play" << endl;}
};


int main()
{
	I instr;
	instr.play();

	W flute;
	flute.play();

	I* pflute=&flute;
	pflute->play();
	pflute->W::play();

	return 0;
}
