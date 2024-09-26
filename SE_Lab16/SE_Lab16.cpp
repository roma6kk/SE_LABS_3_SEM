#include "FST.h"
#include <tchar.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	FST::FST fst1(
		(char*)"abbbcf",				
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst1))
		cout << "Цепочка " << fst1.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst1.strin << " не распознана" << endl;
	FST::FST fst2(
		(char*)"abcbf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst2))
		cout << "Цепочка " << fst2.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst2.strin << " не распознана" << endl;
	FST::FST fst3(
		(char*)"abdbf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst3))
		cout << "Цепочка " << fst3.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst3.strin << " не распознана" << endl;
	FST::FST fst4(
		(char*)"abtbf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst4))
		cout << "Цепочка " << fst4.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst4.strin << " не распознана" << endl;
	FST::FST fst5(
		(char*)"abdbbf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst5))
		cout << "Цепочка " << fst5.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst5.strin << " не распознана" << endl;
	FST::FST fst6(
		(char*)"abdf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst6))
		cout << "Цепочка " << fst6.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst6.strin << " не распознана" << endl;
	FST::FST fst7(
		(char*)"abtf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst7))
		cout << "Цепочка " << fst7.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst7.strin << " не распознана" << endl;
	FST::FST fst8(
		(char*)"abcbb",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst8))
		cout << "Цепочка " << fst8.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst8.strin << " не распознана" << endl;
	FST::FST fst9(
		(char*)"aaaf",
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3)),
		FST::NODE(5, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
		FST::NODE()
	);
	if (FST::execute(fst9))
		cout << "Цепочка " << fst9.strin << " распознана" << endl;
	else
		cout << "Цепочка " << fst9.strin << " не распознана" << endl;

}