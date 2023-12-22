// ALL C SYNTAX (THAT I KNOW)

// HELLO WORLD in C
#include <stdio.h>
int main(void)
{
    printf("hello, World");
}


// --------- thats a syntax for a single line comment-----------
/*
and this is for multiple line comment
*/
#include <stdio.h> // that is a libary that needs to be added if you what its fukcionalytie stdio.h is a standart one that comes with C
#include <cs50.c> // is a additional libary you need to config it // using file.c you compile staticly external lib 
#include <cs50.h> // using file.h you compile dynamicly external lib // at that moment your not able to do so 


//---------COMPILING---------------
//  Dynamic compilation of additional libaries - you use .h files and than the compilor serches  for the file in the libary and compiles it into your binary code
//     when the compilor is not well configured you need to do it with use of bellow mention terminal cmd clang .\addition.c cs50.c -o addition.exe
//  Static compilation of additional lib - using .c files in include 
// to do a static compilation of additional lib you uce terminal cmd // clang .\addition.c -o addition.exe

// --------- MAIN FUNCTION ------------
int main(void)// thats the "main" function it is initialyzed when the program is executed /int means it return a int //(void) means tha it does noe take any values to the functions
{
// thats the main
}


//--------- C VARIABLES--------
int i = 5// integer a digit wiht no.  ex. 4 has - 4beytes
char c  = 'n' // single letter has ex. "f" - 4beytes
bool b = 0 // a True/False statement // 0 is false anny other value is True - 4beytes
float f = 4.5// is a digit with a floting point, a period ex. 4.2 - 4beytes
double d = 2000000// a float with double the storage capasity - 8beytes
long l = 2.000000001 // a int with doble the storage casity - 8 beytes
string  s = "hello" // is not a standart variable in C it comes with <cs50.h> lib or can come with other 
const int j = 2  // const is a cosntante you declare a variable to be a constant that can not be change during the program operation// there fore you need to declare a value of a const variable


// ------PRINTING---------
#include <stdio.h>
int main(void) // that the difference between python to do anything you need to put it into a function
{
    int x = 3; // declering a variable - in C u need to tell what kind of variable it will be here a "int"// x-name of variable // = - is // 3 - value of variable// ; - in every "statement" you need to add a ; at the end
    printf("x is : %i\n", x); //printf comes from stdio.h lib in "" - you put your content do display %i you implay what type of variable value will be dispayed and after , you put the veriable // \n is a special carracter- means move to next line
    float y = 4.0015;
    printf("y is: %.5f\n", y); // %f - means insert a float, %.5f isert a float dispaying 5 dig after the period. in this exaple 4.00150
    printf("%s, %s", s, s);// this is how to insert two strings into a single print
} // there are many special characters ex. \n \t \\ \' ....
// that small prog display a puten into a program value in printf there are may types of variables %d %i %s ..... %c - char// %f - float// %i - integer // %li
// if you want to print a char you use ' ' not " "!!


// -------OPERATION ON VARIABLES--------------

//MATEMATICAL OPERATIONS
// with int  float double long  you can do all math operations in stdin.h + - * / and % - the rest of division
// on char-s you can do + - to shift thery value in ASCII chart
int a = 1; 
a++; // if you want to increment by 1 this is the same as a = a +1 or a += 1
a+=1;


//VARIABLE COMPERING
//you can compare with ease int bool float dobule but not strings
// the comparmet return is a boolien value 0 or any other than 0 ro true/false 
a == 1; // is equal to 
a != 2: // is not equal to  
a == 1 || b != 1; // || is or
a == 1 && b != 1;// && is and
// you can use all of the following < > >= <= == !=


//TYPE CASTING (changing one variable to another) it is usefull to type cast in certain situation
//some variables have size limitation for example or precision that you would like to change
int b = 1;
c = (double)b ; // this is how you change a int into a double (that does not have any intugeroverflow issues)
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int x = 5, y = 7;
    printf("%lf\n", (double) x + y ); // typacasting to double and adding before displaying
}
//_______________________________________
//OPERATION ON STRINGS ARE ON IN ARRAYS 
//__________________________________


// there are othre lib that can make it easer
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int x = get_int("insert your int\n"); // you don need to declare in advance what type of varable it will be. 
    char y = get_char("insert your char\n"); 
    double z = get_double("insert your char\n");
    float w  = get_float("insert your float\n");
    string u = get_string("insert your string\n"); // if the compilator configurated incorrectyl it will not work
}


//----------------CONDITIONALS -----------

// exapmple bellow// if needed use || or operators or && and poerators to combine your conditions
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int x = get_int("What's x? "); // 
    int y = get_int("What's y? ");
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is not less than y\n");
    }
    else
    {
        printf("x i equal to y\n");
    }
}

// switch not used  often
// it will compare the 
#include <stdio.h>
int main(void)
{
    int i = 2;
    switch(i)// it will compare the varaible in () with the valeuses in the cases
    {
        case 1: // if the values are the same tan it will execute the values after : if not it will skip but 
            printf("i = one\n"); // if it will execute the case than he will execute until it "hits the break
            break; // if the i value would be 1 and no break; here it would execute the case 1 and case 2 until hiting the break key ward
        case 2:
            printf("i = two\n");
            break;
        default:
            printf("i is not two or one");
    }
    return 0;
}

//---------------LOOPS---------------------

// FOR LOOP
#include <stdio.h>
int main(void)
{//printing Hi 3 times
    for (int i = 0; i < 3; i++) // it will loop until the condition is true
    {
        printf("Hi\n");
    }
}

// WHIEL LOOP
#include <stdio.h>
int main(void)
{
    int i = 0; // declaring the varialbe and its value in advance 
    while (i < 3) // while the condition is True it will loop
    {
        printf("Hi\n");
        i++;
    }
}

// DO WHILE LOOP
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int n; // you need to declare a variable and its type to call on it 
    do // slight diference between the while loop the checed condition time is different
    {
        n = get_int("Size: "); // get_int is from cs50.h lib
    }
    while (n < 1);
}

//LOOPS WITH CONDITIONALS
#include <stdio.h>
#include <stdbool.h> // to have true operator  // otherwise you woud use 0 albo 1 
int main(void)
{
    int n = 0;
    while (true) 
    {
        n++;
        if(n!=3)
        {
            printf("n is not 3 its %d\n", n);
            continue; // the continue will push the program back to the loop begining not 
        }
        else if(n==3)
        {
            printf("n is equal to 3 \n");
            break; // break  - breaks out of the loop 
        }
    }
    printf("loop end\n");
}


//----------------------ARRAYS---------------------
// array is a order elements of pericular type

#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int int_array[2] = {2,3}; // declaring a array// the elem are ints/ array name//[size of array] = {first elem, second element} 
    printf("%i", int_array[0]); // it will print the first element in an array// index nr 0
    for (int i = 0; i <= 2; i++ )
    {
        int sum += int_array[i]; // ass you can see you can iterate throu the array elements
        printf("sum is %d",sum);
    }
}

// below some char arrya examples // which we call strings 
#include <stdio.h>
int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    printf("%i %i %c%c \n", c1, c2, c1, c2);// a arawy of chars can be a string // a char can be represeted as a integer value (ACSII)
}

#include <stdio.h>
#include <cs50.c>
int main(void)
{
    string s = "HI!";
    printf("%i %i %i\n", s[0], s[1],s[2] ); // so as pointed out strings is in deed a array // can be displayed as int or chars
}

//below an array of an array
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    string words[2]; // as before the array needs to be a declared size
    words[0] = "Hi"; // this line will assing a first subarray to the 2 element array words
    words[1] = "bye";
    printf("%s %s \n", words[0], words[1] ); 
    printf("%i%i %i%i%i\n", words[0][0], words[0][1], words[1][0], words[1][1], words[1][2]); // so you can do a array of an array
    printf("%i %i %i %i \n", words[1][0], words[1][1], words[1][2], words[1][3]); // it should print so printed out 0 simpolizes null \0
}

// STRINGS AS ARRAYS 
//if the string is a arraych of charcters (chars) you can do array operations on it

//operation on strings
#include <stdio.h>
#include <cs50.c>
#include <string.h> //a lib that has many strings functions like strlen() 
int main(void)
{
    string name = ("Thomas");
    int n = strlen(name);// strlen(<string>) is a function that will count the amout of letters in the words - elements in the arrays
    printf("the word is %i letters long\n",n);
    for (int i = 0; i < strlen(name); i++) // this loop will change letters to upper case
    {
        if(name[i]>= 'a' && name[i <= 'z'])
        {
            printf("%c", name[i]-32);
        }
        else
        {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}
//the same thing can be achived with other libs
#include <stdio.h>
#include <cs50.c>
#include <string.h> //string operations
#include <ctype.h> // lib that hass many usefull operations lite toupper()
int main (void)
{
    string s = get_string("Before: ");// at the moment get_string does not work
    //printf("Before: %s\n", s);
    printf("After:  ");  
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", toupper(s[i])); // changes the char to its upper "value"
    }
    printf("\n");
}

//strcmp() function form string.h
#include <stdio.h>
#include <cs50.c>
#include <string.h>
int main(void)
{
    string names[]={"tom", "dan", "bob", "rob"};  // this is who you can eter the value into an arrys
    //below lines usubstitudes get_string()
    char s[4] ;
    printf("what person are you looking for?: ");
    fgets(s, sizeof(s), stdin);
    //printf("You are looking for: %s\n", s); 

    int size = sizeof(names)/sizeof(names[0]); // this will give us a size of array
    //printf("how many names: %i\n", size);

    for(int i = 0; i < size; i++)
    {
        //printf("i is %i\n", i); // this lines where important to understand the search
        //printf("is %s, %s ? \n", s, names[i]);
        //printf("strcmp value is : %i\n", strcmp(names[i], s));
        if (strcmp(names[i], s) == 0) // you can not use == with string like in python// strcmp compers strings it will return a int 0 for True // from string.h
        {
            printf("person found\n");
            return 0;
        }
        //printf("\n");
    }
    printf("person not found\n");
    return 1;
}
//strcpy_s function from string.h
#include <string.h>
    strcpy_s(t, strlen(s)+1, s)// str copy function // form the documentation the strcpy_s needs !3 arguments ! (the char* that you copy to,lenght of the future string, the char* that you copy from)
//------------------


//--------------FUNCTIONS-----------------
//if you want to declare a function that has a array in it you can without adding the arry size

//function with different value input and different output
#include <stdio.h>
#include <cs50.c>
int get_size(void); // idicate to a function that will be defined later // declaring a fun also caled protoype // definition is below 
void print_grid(int size);// a prototype is just use first line of a function 
int main(void) // Main function is a function beeing executed while the exetucaple is opened// All main funct return a int but can take any variable in here none.
{
    int n = get_size(); // here you can call the function
    print_grid(n);
}

int get_size(void) // here is the function def . // this function returns a int and will take(have imput of )nothing.
{
    int n;
    do
    {
        n = get_int("what size of grid?: ");
    }
    while(n<1);
    return n; // n variable (a int) will return from the function
}

void print_grid(int size)// here is the funciton definition // the function returns nothing(void), but takes (has a input of) a int.
{
    for(int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//using the main function int return
#include <stdio.h>
#include <cs50.c>
int main (int argc, string argv[]) // here the main function will take values // 
// argc - is argument count (self expanotary) this is why its a int// argv an array of characer pointers (strings) in this case
{/
    if(argc < 2)
    {
        printf("Missing valume\n");
        return 1; // it is convetion that if main outputs 1 it means that smth went wrong
    }
    else 
    {
        printf("hello, %s\n", argv[1]);
        return 0;// it convention if main performed corectly it outputed 0
    }
}


// ------------- DATA STRUCTURE ---------------

#include <stdio.h>
#include <cs50.c>
#include <string.h>
typedef struct // is a way to creating a data structure // typedef -declarse that type// is a keyword to define a new data type
{
    string name; // type of data , name of data 
    string number;
}
person; // the name of the data structure
//below a use if that defined data structure
int main(void)
{
    person people[2]; // accsing strucure elemt
    people[0].name = "tom";
    people[0].number = "69";

    people[1].name = "bob";
    people[1].number = "666";

    char s[4] ;
    printf("Whos number do you want?: ");
    fgets(s, sizeof(s), stdin);

    int size = sizeof(people)/sizeof(people[0]); // this will give us a size of array
    //printf("size of people is %i\n", size);
    for(int i = 0; i < size; i++)
    {
        if (strcmp(people[i].name, s) == 0) // you can not use == with string like in python// strcmp compers strings it will return a int 0 for True // from string.h
        {
            printf("person found\n");
            printf("The numebr is %s\n", people[i].number);
            return 0;
        }
        //printf("\n");
    }
    printf("person not found\n");
    return 1;
}


//-----------------RECURSION-----------------------
//recursion is a proces of function trigering itself
//iteration.c // which is not recursion
#include <cs50.c>
#include <stdio.h>
void draw(int n);
int main (void)
{
    int height = get_int("how high:? ");
    draw(height);
}
// the below function interates over with use of a loop // recurtion can be a bit more sufisticated 
void draw(int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j  < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//recurtion.c
#include <stdio.h>
#include <cs50.c>
void draw(int n);
int main (void)
{
    int height = get_int("how high:? ");
    draw(height);
}

void draw(int n)
{
    if (n<=0)
    {
        return;
    }
    //printf("current n value is : %i\n", n); // for debugging purpase
    draw(n-1);// it will diminish the value of n and reegnites the function// after tha it will unwind it self going from 1 all the way to n
    // printf("berofe the for loop n valune is %i\n", n); // for debugging purpase
    for(int i = 0; i<n; i++)
    {
        // printf("n valune is %i", n);
        printf("#");
    }
    printf("\n");
}


// --------------------ERRORS -----------------------
#include <stdio.h>
#include <cs50.c>
int main (int argc, string argv[])
{
    if(argc < 2)
    {
        printf("Missing valume\n");
        return 1; // it is convetion that if main outputs 1 it means that smth went wrong
    }
    else 
    {
        printf("hello, %s\n", argv[1]);
        return 0;// it convention if main performed corectly it outputed 0
    }
}


// ---------------- MEMORY------------------------
// location in memory is define in the hexadecimal system or base-16 // 0 1 2 3 4 5 6 7 8 9 A B C D E F// F=15 
// ex FF = 0x255 // 0x is a preffix so the computer know that is dealing with a base-16 system
// & is a symbol of an adress
// * is a sybol of a pointer

// ------------ POINTERS & MEMORY LOCATION----------
#include <stdio.h>
int main(void)
{
    int a;    // Declare an integer variable 'a'
    int *b;     // Declare an integer pointer 'b' it is an adres we can dereferance with *
    printf("value of a: %d\n", a);     // Print the value of 'a'
    printf("adres of a: %p\n", (void*)&a);    // Print the address of 'a'
    b = &a;// Point 'b' to the address of 'a'
    printf("vale that b is pointing to: %d\n", *b);// Print the value pointed to by 'b'
    printf("adres stored in b: %p\n", (void*)b);// Print the address stored in 'b'
    int c = 4;// Declare an integer 'c' and initialize it to 4
    int *d = &c;// Declare an integer pointer 'd' and point it to the address of 'c'
    *d = 5;// Assign the value 5 to the variable pointed to by 'd'
    printf("adress of c: %p\n", &c);// Print the address of 'c' (not the value of 'c')
    printf("the value of c:%d", *d); // prints the value that 'd' is pointing to (value of 'c')
}

//--------CHAR POINTERS - STRINGS ----------------
#include <stdio.h>
int main(void)
{
    char *s = "HI!"; // this is a char pointer - a string 
    printf("%s\n",s); // printf know that it should display the values from the first character all the way to null \0 -
    printf("%p\n",s); // but when u use %p it will display the first character position
    printf("%p\n",&s[0]); // & will show the varibale location of the varialme (first character in the s array)
    printf("%p\n",&s[1]);
    printf("%c\n",*s); // %c will print the first charracter // *s means go to the adres
    printf("%c\n",*(s+1)); // %c will print the second charracter // you can do a pointer aritmetic this character + 1
    printf("%c\n",*(s+5000000)); // if you look for at a memory that you shouldend you will get the segmentation error
// becouse a string is just a pointer to a adres of the first character doing == to strings will not work
// == in strings will compare the adresses not the values in the adreses
}

//swap.c
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b); // remember the prototype
int main (void)
{
    int x = 1;
    int y = 2;
    printf("x is: %i and y is : %i\n", x, y); 
    swap(&x,&y); // but you need to give adresses to the funcition 
    printf("x is: %i and y is : %i\n", x, y);
    return 0; 
}
// void swap(int a, int b)// that doesnt work
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
void swap(int *a, int *b)// but when u use pointer you "say" go the the value of the adres 
{
    int tmp = *a; // asign the temp variable what is a pointing to 
    *a = *b; // asign  what is a pointing to waht is b pointing to //dereferencing
    *b = tmp; // asign waht is b pointing value from temp //dereferencing
}

//comparing strings.c
#include <stdio.h>
#include <string.h>
int main()
{
    char i[4] ; // in here i request for 4 chars in memory
    printf("i: ");
    scanf_s("%s5", i);
    char *j = "hi!";//*j is adres location
    //if (*i == *j) // in here if compares only the first character wich might me the same
    if (i == j) // here if compares the adresses of first charactes which will be alwys different(for different variables)
    {
        printf("same\n");
    }
    else
    {
        printf("Different\n");
    }
    // as pointed out by the below output the String content is the same but the adress is different and that is what is being compared
    printf("j: %s\n",j);
    printf("adress of j: %p\n", &j); // a
    printf("i: %s\n",i);
    printf("adress of i: %p\n", &i);
}


//-----------MALLOC & FREE------
// before the variables landed to the stack with mallac they will land on a heap
//string is a char with a pointer of the variable as pointed below

int x, u; // declaring an integer variable x and u that will take place in the stack
float y[x]; // declaring a float array of x elements on a stack 
float *z = malloc(x* sizeof(float)); // declaring a float array of x elements on a heap
char * word = malloc(n * sizeof(char)); // declering a array of chars (a string ) of size of n on a heap
free(word); // freeing the heap memory form the word array
// every memory block of memory malloc-ed needs to be freed, only memory malloc() needs to be free, dont free twice
int m;
int *a:
int *b= malloc(sizeof(int));
a=&m;
a=b; //a is poiting to the malloc-ed memory space
m = 10; // assignig a value of m
*b = m+2; // go to the value that a (,b) points to and asing that is m+2

//copy_string_fail.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char s[] = "hello!"; 
    printf("%s\n", s);
    printf("%i\n", (int)strlen(s));
    printf("%i\n", (int)sizeof(s));
    char *t = s; // here i try to "copy" the value
    printf("%c\n", t[0]);
    printf("%c\n",t[0]-32 );
    if (strlen(t)>0)
    {
        t[0] = toupper(t[0]); // here i try to change the copied string first charracter
    }
    printf("s: %s\n", s); // here i can sea that i changed the fist charracter in both s and t
    printf("t: %s\n", t); // becouse in line "char *t = s" i copied the adress of the first charracter not its value
}

// copy_string.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    char *s = "david";
    char *t = malloc(strlen(s)+1);// *t is a pointer to an unused memory that we request by malloc from the heap 
    printf ("t:%s\n", t);// printing a garbidge of the memory that t is pointing to 
    if (t == NULL ) // its good practise that when requesting a memory you check if there is any
    { // form the malloc doc. if there is no memory available it will reutn NULL
        return 1;
    }
    strcpy_s(t, strlen(s)+1, s); // str copy function // form the documentation the strcpy_s needs !3 arguments !
    printf("s:%s\n", s);
    printf("t:%s\n\n", t);
    if(strlen(t)>0)
    {
        t[0] = toupper(t[0]); 
    }
    printf("s:%s\n", s);
    printf("t:%s\n", t);// now the are diferent values
    free(t); // when your done with the variable free it 
    printf("t:%s\n", t);// again printing a garbidge vaules 
    return 0; 
}

// --------REALLOC------
// if you have a fixed number or alocated momory and you want to change it you use realloc(adres,size) as on the ex. below
//list_reallocating_.c
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *list=malloc(3 *sizeof(int));
    if (list==NULL)
    {
        return 1;
    }
    list[0]= 1;
    list[1]= 2;
    list[2]= 3;
    //....
    int *tmp = realloc(list, 4*sizeof(int)); // realloc is a function to reallocating memory with resizing
    if(tmp == NULL)
    {
        free(list);// here if there is no memory to allocate for the tmp lets free the list memory
        return 1;
    }
    list = tmp;
    tmp[3]= 4;
    for(int i = 0; i<4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(tmp);
    return 0;
}

//--------------- MEMORY LEAKS CHECK-----------------
//memory.c // suposed to use valgrind but i did use drmemory // in terminal // drmemory -- filename.exe
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int *x = malloc(3 * sizeof(int));
    if(x == NULL)
    {
        return 1;
    }
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    free(x);
}


// ------ GARBADGE VALUES-------------
//garbage.c
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int scores[1240];// without assigning values to an variable there will be garbadge values 
    for (int i = 0; i < sizeof(scores); i++)
    {
        printf("%i\n", scores) // printing garbadge values //there can be anything
    }
}

//------------INPUT--------------
//standart lib
#include <stdio.h>
int main(void)
{
    int _int;
    float _float;
    double _double;
    char _char;
    char _string[50]; // in stdio lib there is no string -- string is a array of chars
    printf("insert your int\n");
    scanf("%d", &_int); // this will look what is putten int the termian and assing a value to the variable called _int
    printf("insert your float\n");
    scanf("%f", &_float);
    printf("insert your double\n");
    scanf("%lf", &_double);
    printf("insert your char\n");
    scanf("%c", &_char);
    printf("insert your sting\n");
    fgets(_string, sizeof(_string), stdin);
    printf("insert your sting\n");
    scanf_s("%s5", _string);// %s5 this will insert max 5 characters
}


//------- WORKING WITH FILES -----------------------
//working with csv files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *csv_file;

int main(void)
{
    errno_t csvfile; // not quite know waht that syntax id for but you need a errno_t type of a variable to open a file
    csvfile = fopen_s(&csv_file, "cvs_file.csv","a"); // opens the file 

    char name[10];
    printf("name up to 10 charracters: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';//strcspn() searches for a first ocurance of a char i string returns the index of it
    //name[strcspn(name, "\n")] = '\0'; is to get rid of the \n that is automaticly in the string from the fgets()

    char number[10];
    printf("number up to 10 dig: ");
    fgets(number, sizeof(number), stdin);

    fprintf(csv_file, "%s,%s", name, number);

    fclose(csv_file);
}

//------- POINTERS IN DATA STRUCTURE & RECURSION -----------------------
//lined_list.c
#include <stdio.h>
#include <stdlib.h>
typedef struct node // you need to add here name of the node if the node apperse as a varibale in a data structure, so you can self refrence it (like a recursion)
{
    int number;
    struct node *next; // here you need to add struct as for the above reson
}
node; // name as usual 

int main(int argc, char *argv[]) // here we give command line arguments// remainder -a argc is the argument count, argv[] is a list of char pointers
{
    node *list = NULL; // now you have a list of 0 elements / list in the first pointer of the node structure
    // here the link list takes form the terminal the values and puts it into the linked list 
    // the list orders so that the new element is at the begining of the list
    for(int i = 1; i < argc ; i++) // i stars at 1 becouse 0 is the file name of the argv //as per the functions 
    {
        int num = atoi(argv[i]); // here we assign the current value from the command promt to the num variable
        // atoi is a function changes a str to an int atoi (ascii to int) 
        node *n = malloc(sizeof(node)); // here we declare a tmp vairable pointer of the node data type and assigning memory by using malloc
        if(n == NULL)
        {//here we check if we have enought space for the varibale 
            return 1; // but in situation that for the second or third element there will be no space you should free the previus nodes from the l.list
        } // so the code is not complete Valgrin or drmemory could point out potential memory leak

        n->number = num; // this gives the value to the element form the num variable // n->number = num; is the same as (*n).number = num;
        n->next = NULL; // here we make sure that the pointer to the next node from the current one is not garbadge value so we assign it NULL bacouse we didnt assign it any value

        n->next = list; // the next should point to the begining of the list which will point to the next element and so we will append 
        list=n; // here we assign the first element to the temp node structure // if that line of code would be before the prievus we would caused a memory leakby orthining the seconde and so one elem.
    }

    node *ptr = list;// declaring a tmp from nude struct pointer for displaying that points at the first element
    // while (ptr !=NULL) // it could be done with a for loop 
    // {
    //     printf("%i\n", ptr->number); // print what the ptr is pointing to 
    //     ptr = ptr->next; // move to the next pointer  
    // }
    for(node *ptr = list; ptr !=NULL; ptr=ptr->next ) // or a while loop as
    {
        printf("%i\n", ptr->number); // print what the ptr is pointing to 
        
    }

    ptr=list;// here ptr is again pointing to the begining of the list
    while (ptr != NULL)//here we free all the allocated memory that was used while creating the l. list
    {
        node *next= ptr->next; // here we create a tmp pointer next that points th the pointer of the first eleent 
        free(ptr); // here we free the vlalue of the first element
        ptr= next;//here we reassign the ptr pointer to point to the next element
    }
}


