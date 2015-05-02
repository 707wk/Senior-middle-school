int fun1(int n)
{
	int i;
	for(i=2;i<n;i++)if(n%i==0)return 0;
	return 1;
}
int fun(int n)
{
	int i,sum=0;
	for(i=1;i<=100;i++)
	if(fun1(i))sum+=i;
	return sum;
}