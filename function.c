int sum(int,int);  //function declaration
int main(int argc, char** argv) {
    int a,b,c; 
    printf("Enter the numbers:");
    scanf("%d%d",&a,&b);
    c=sum(a,b);  //function call, a and b are arguments
    printf("\nSum is %d",c);
    return (EXIT_SUCCESS);
}
int sum(int x,int y) {  //function definition, x and y are parameters
    int z=x+y;
    return z;
