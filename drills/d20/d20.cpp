#include "../GUI/std_lib_facilities.h"

template<typename A>
void print(const A& a){
	for(auto& au : a){
		cout<<au<<" ";
	}
	cout<<'\n';
}

template<typename A>
void inc(A& a, int n){
	for(auto& au : a){
		au=au+n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 own_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 i=f1; i!=e1; i++){
		*f2++ = *i;
	}
	return f2;
}

int main(){

	constexpr int size=10;

	int tomb[size] = {0,1,2,3,4,5,6,7,8,9};
	cout << "int tomb: ";
	print(tomb);

	vector<int> v(size);
	copy(tomb, tomb+size, v.begin());
	cout << "a tombbol masolt vector: ";
	print(v);

	list<int> l(size);
	copy(tomb, tomb+size, l.begin());
	cout << "a tombbol masolt lista: ";
	print(l);

	array<int, size> arr;
	copy(tomb, tomb+size, arr.begin());
	cout << "a tombbol masolt array: ";
	print(arr);

	array<int, size> arr2=arr;
	cout << "masodik array: ";
	print(arr2);
	vector<int> v2=v;
	cout << "masodik vector: ";
	print(v2);
	list<int> l2=l;
	cout << "masodik lista: ";
	print(l2);
	
	inc(arr2, 2);
	cout << "megnovelt array: ";
	print(arr2);	
	inc(v2, 3);
	cout << "megnovelt vector: ";
	print(v2);	
	inc(l2, 5);
	cout << "megnovelt lista: ";
	print(l2);	

	own_copy(arr2.begin(), arr2.end(), v2.begin());
	own_copy(l2.begin(), l2.end(), arr2.begin());
	cout << "masolas utani array: ";
	print(arr2);
	cout << "masolas utani vector: ";
	print(v2);
	cout << "masolas utani lista: ";
	print(l2);

	vector<int>::iterator it;
	it=find(v2.begin(),v2.end(),3);
	if(it != v2.end()){
		cout << "A 3 kovetkezo helyen talalhato: " << distance(v2.begin(),it) << endl;
	}
	else cout << "A 3 nem talalhato." << endl;

	list<int>::iterator lit;
	lit=find(l2.begin(),l2.end(),27);
	if(lit!=l2.end()){
		cout << "A 27 a kovetkezo helyen talalhato: " << distance(l2.begin(),lit) << endl;
	}
	else cout << "A 27 nem talalhato." << endl;

	return 0;
}