int main(){
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	if(n>90 && n<=100)
		cout<<"Excellent\n";
	else if(n>80 && n<=90)
		cout<<"Well Done\n";
	else if(n>70 && n<=80)
		cout<<"Good\n";
	else if(n>60 && n<=70)
		cout<<"Better luck next time.\n";
	else if(n>50 && n<=60)
		cout<<"Needs more effort\n";
	else
		cout<<"Failed\n";
}
