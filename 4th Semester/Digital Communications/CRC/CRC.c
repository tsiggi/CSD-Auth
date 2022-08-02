/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                   *
*                            JUNE 2022                              *
*								                                    *
*                      DIGITAL COMMUNICATION                        *
*		                        CRC			                        *
*								                                    *
* 	             CHRISTOS-ALEXANDROS TSINGIROPOULOS	                *
* 			                 ΑΕΜ : 3872		                        *
*								                                    *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>     /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define k 20                                                // SIZE OF MESSAGE DATA
#define BER 0.001                                           // BIT ERROR RATE
#define max 1000000000                                      // NUMBER OF MESSAGES

void print_Str(char*, int);                                                 // NOT USED! used for debugging   Prints string
void read_binary(char*, int*);                                              // NOT USED! used for debugging   Reads & Checks binary input
int check_HelpingFunction(const char*, int*);                               // NOT USED! used only in read_binary
void create_Message(char*);
void get_2nkD(char *,const char*, int);
char* get_R(const char* D_2nk, int n,char* P,int size_p,int* size_of_r);
int subtract_mod2(char* ,const char* ,int);
char* get_T(const char* D_2nk,int size_of_D2nk, const char* FSC, int size_of_FCS);
int CRS(char* T, int size_of_T, char* P, int size_of_p);
int BitErrorRate(char* T,int size_of_T ,double ber);

int i;

int main(void) {
    int known_errors = 0 ;                                                  // Errors that we KNOW  from BitErrorRate function
    int found_errors = 0 ;                                                  // Errors that we FOUND from CRS function

    time_t t;

    char P[6] = {'1','1','0','1','0','1'};
    int size_p = 6;
    //read_binary(P, &size_p);                                          // Binary Number P that is inserted from user
    //print_Str(P,size_p);                                              // Debugging

    // initialize random seed: /
    srand (time(&t));

    int n = k + size_p - 1;                                             // n = size of D_2nk and T
    int size_fcs;                                                       // size of FCS
    char D[k] = {0};
    char *D_2nk = malloc(n * sizeof(char));                        //initialize the 2^(n-k) * D  that has n bits
    char *T;
    char *FCS;



    for(int j=0;j<=max;j++) {

        if(j%1000000 == 0){
            // Notifies the user about the simulation status
            printf("Done = %.1f%\n",(j/(1.0*max))*100);
            //printf("\x1b[A");         //clears the screen in LINUX
        }

//--------------------------------- 1st Stage ---------------------------------
// Create a binary message, with the same possibility for 0,1 in every position

        //D is a char array that is randomly created with maximum k bits (maximum because it may return 00011 so k=2 & not 5)
        create_Message(D);
        // print_Str(D,k);                                                              // Debugging


//--------------------------------- 2nd Stage ---------------------------------
//                      Calculate D*2^(n-k) for this message

        // calls the function that calculates 2^(n-k) * D
        get_2nkD(D_2nk, D, n);
        // print_Str(D_2nk, n);                                                         // Debugging


//--------------------------------- 3rd Stage ---------------------------------
//                      Calculate CRC(FCS) for this message

        // FCS = remainder of D_2nk / P  ( modulo-2 calculations !!! )
        // calls the function that calculates and returns the FCS sequence of n-k bits
        FCS = get_R(D_2nk, n, P, size_p, &size_fcs);
        // print_Str(FCS, size_fcs);                                                    // Debugging

//--------------------------------- 4th Stage ---------------------------------
//                 Calculate T = D*2^(n-k) + FCS for this message

        // calls the function that calculates and returns the  T  sequence of  n bits
        T = get_T(D_2nk, n, FCS, size_fcs);
        // print_Str(T, n);                                                             // Debugging


//--------------------------------- 5th Stage ---------------------------------
//                       Calculate T' = RECEIVED MESSAGE

        // Returns 1 if this Message was changed because of the transfer
        known_errors += BitErrorRate(T,n,BER);
        // print_Str(T, n);                                                             // Debugging


//--------------------------------- 6th Stage ---------------------------------
//                           Find if T' has an ERROR

        // if T / P (modulo-2 calc) remainder is not 0 then WE HAVE AT LEAST ONE BIT CHANGED WHILE TRANSFERRING THE DATA
        if (0 == CRS(T, n, P, size_p) ){
            //printf("There was a problem!!");                                          // Debugging
            found_errors ++ ;
        }
        free(FCS);      // free space
        free(T);        // free space
    }

    printf("\n\nCRC Simulation has finished.\nThe results are:\n\n");
    printf("\nMessages that got an error: %.7f% \nMessages found to have an error from CRC: %.7f%\n" ,(known_errors/(double)max)*100 , (found_errors / (double)max) * 100);
    printf("\nPercentage of messages that have an error and are not traced from CRC : %.8f%\n",((known_errors-found_errors)/(double)known_errors)*100);


    system("pause");
    return 0;
}
/** Input : *String = that we want to print , N = size of string
 *  Output : Prints one by one every character of the string
 *  Return : void
 */
void print_Str(char* str,int n){
    for(i = 0; i< n;i++)
        printf("%c",str[i]);
    printf("\n");
}

/** Input : *String = address of a string , *size = address of the size of string
 *  Asks for a string input. We save input at input address. Checks if  string
 *  is binary with check_HelpingFunction() and updated the size value
 *  Return : void
 */
void read_binary(char *str,int *size){
    // str = store the input (BINARY) as an array of char (0,1)
    // size = size of STR

    // read INPUT & check if it is BINARY
    printf("Give a binary number :");
    scanf("%s",str);

    int flag = check_HelpingFunction(str , size);

    while(flag){
        printf("\n\nTRY AGAIN!!!\nGive a BINARY number (starts with 1 & smaller than 30 bits) [e.g 110001] :  ");
        scanf("%s",str);

        flag = check_HelpingFunction(str , size);
    }
}

/** Input : *p = string that we want to check , *size = address of the size of string
 *  Checks each and every char of the string if the value is 0 or 1
 *  Return : 0 if every char is 0 or 1 , else returns 1       (0=Binary,1=NotBinary)
 */
int check_HelpingFunction(const char* p,int *size){
    if(p[0]=='0')
        return 1;

    for(i=0;p[i]!='\0';i++){
        if(p[i]!='1' && p[i]!='0'){
            *size = i;
            return 1;
        }
    }
    *size = i;
    return 0;
}

/** Input : *D = address of a string with size = k
 *  Initializes every char of the string with '0' or '1'  (SAME POSIBILITY)
 *  Return : void
 */
void create_Message(char* D){
    for(i = 0; i < k; i++ ){
        double foo = (double)rand()/(double)RAND_MAX;
        D[i] = foo>0.5 ? '1' : '0';
    }
}

/** Input : *D_2nk = address of a string with size = n, D = address of a string with size = k, n = size of D_2nk
 *  Stores at the first k positions of D_2nk the D string and in the last n-k position '0'
 *  Return : void
 */
void get_2nkD(char *D_2nk, const char* D , int n) {
    for (i = 0; i < n; i++) {
        if (i < k)
            D_2nk[i] = D[i];
        else
            D_2nk[i] = '0';
    }
}

/** Input : *D_2nk = address of a string with size = n, n = size of D_2nk
 *  Input : P = address of the predefined string , size_p = The size of P
 *  Calculates the remainder of D_2nk / P           ( XOR / )
 *  Creates a String : and initializes it with the remainder
 *  Return : the created String
 */
char* get_R(const char* D_2nk, int n,char* P,int size_p,int* size_of_r){
    int count = 0 , c1 = 0;
    char *temp = malloc(size_p* sizeof(char));
    // initialize temp
    for(i=0;i<size_p;i++)
        temp[i]=D_2nk[i];

    while(n-count>=size_p){
        // temp / p       (xor /)
        c1 = subtract_mod2(temp,P,size_p);      // c1 = missing elements of temp
        count += c1;

        i = - c1 ;
        // updates temp  ( inorder not to have missing elements ) and be ready for the next (xor /)
        while(1){
            if(i == 0 || count+size_p+i == n)
                break;
            temp[size_p+i] = D_2nk[count+size_p+i];
            i++;
        }
    }
    // Calculates temp size
    count = 0;
    for(i=size_p-1;i>=0;i--){
        if(temp[i]=='-')
            count ++;
        else
            break;
    }

    *size_of_r = size_p-count;
    return temp;
}

/** Input : *temp = address of dividend
 *  Input : P = address of divisor , size_p = The size of P & temp
 *  Calculates the remainder of temp / P           ( XOR / )
 *  and stores the result in temp
 *  Return : the missing elements of temp after the division
 */
int subtract_mod2(char* temp,const char* p,int size_of_p)
{
    int flag=0,count=0,j=0;
    for(i=0;i<size_of_p;i++){
        if(flag==0){
            if(temp[i]==p[i])
                count++;
            else{
                flag = 1;
                temp[j] = '1';
                j++;
            }
        }else {
            if(temp[i]==p[i])
                temp[j] = '0';
            else
                temp[j] = '1';
            j++;
        }
    }
    // temp = remainder
    for(;j<size_of_p;j++)
        temp[j]='-';

    return count;
}

/** Input : *D_2nk = address of a string with size = n, size_of_D2nk = size of D_2nk
 *  Input : FSC = address of the remainder string , size_of_FCS = The size of FCS
 *  Creates a new string with size n .
 *  Initializes the first k positions with D_2nk
 *  Initializes the last n-k positions with FCS
 *  Return : the created String
 */
char* get_T(const char* D_2nk,int size_of_D2nk, const char* FSC, int size_of_FCS){
    char * T = malloc(size_of_D2nk * sizeof(char));
    for(i = 0 ; i < size_of_D2nk ; i++ )
        T[i] = D_2nk[i];

    for(i = 1; i <= size_of_FCS; i++)
        T[size_of_D2nk - i] = FSC[size_of_FCS -i];

    return T ;
}

/** Input : *Τ = address of the arrived message , size_of_T = size of T
 *  Input : P = address of the predefined string , size_of_p = The size of P
 *  Checks if remainder of T / P is 0       (XOR /)
 *  if it is then CRC did not find an error
 *  else there is for sure an error
 *  Return : 0 if CRC finds an error , 1 otherwise
 */
int CRS(char* T, int size_of_T, char* P, int size_of_p){
    int int_temp;
    char *temp = get_R(T, size_of_T, P,size_of_p,&int_temp);

    for (i=0;i<int_temp;i++){
        if(temp[i] != '0' && temp[i] !='-'){
            free(temp);
            return 0;                           // Something is Wrong
        }
    }
    free(temp);
    return 1;                               // Everything is Good
}

/** Input : *Τ = address of final message, size_of_T = size of T
 *  Input : ber = bit error rate
 *  Uses a random function that returns a value [0...1]
 *  For every char of T string if random < ber change char
 *  Return : 1 if we have at least one change, 0 otherwise
 */
int BitErrorRate(char* T,int size_of_T ,double ber){
    int flag = 0;

    for(i=0;i<size_of_T;i++){
        double foo = (double)rand()/(double)RAND_MAX;   // foo = [0..1]
        if( foo < ber ){
            T[i] = T[i]=='0' ? '1' : '0';
            flag++ ;
        }
    }
    return flag>0 ? 1 : 0;
}


