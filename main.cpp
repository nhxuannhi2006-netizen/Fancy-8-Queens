#include <iostream>
using namespace std;

int main(){
    int i,j,k,l;
    typedef char box[5][7];
    box wb, bb, wq, bq, *board[8][8];

    for(i=0;i<5;i++)
        for(j=0;j<7;j++){
            wb[i][j]= ' ';
            bb[i][j]=char(219);

            wq[i][j]= ' ';
            bq[i][j]=char(219);
        }

    char WQ[5][7] = {
        {' ',' ',' ',' ',' ',' ',' '},   
        {' ', char(219),' ',char(219),' ',char(219), ' '},
        {' ',char(219),char(219),char(219),char(219), char(219),' '},
        {' ',char(219),char(219),char(219),char(219), char(219),' '},
        {' ',' ',' ',' ',' ',' ',' '},
    };

    char BQ[5][7] = {
        {char(219),char(219),char(219),char(219),char(219),char(219), char(219)},
        {char(219),' ', char(219),' ', char(219), ' ', char(219)},
        {char(219),' ',' ', ' ',' ',' ',char(219)},
        {char(219),' ',' ', ' ',' ',' ',char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
    };

    for(i=0;i<5;i++)
        for(j=0;j<7;j++){
            wq[i][j]=WQ[i][j];
            bq[i][j]=BQ[i][j];
        }

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0) 
                board[i][j]=&wb;
            else 
                board[i][j]=&bb;

    int q[8]={0,4,7,5,2,6,1,3};

    for(int col=0;col<8;col++){
        int row=q[col];
        if((row+col)%2==0) 
            board[row][col]=&wq;
        else 
            board[row][col]=&bq;
    }

    cout<<" ";
    for(i=0;i<7*8;i++) cout<<"_";
    cout<<endl;

    for(i=0;i<8;i++){
        for(k=0;k<5;k++){
            cout<<char(179);
            for(j=0;j<8;j++)
                for(l=0;l<7;l++)
                    cout<<(*board[i][j])[k][l];
            cout<<char(179)<<endl;
        }
    }

    cout<<" ";
    for(i=0;i<7*8;i++) 
        cout<<char(196);
    cout<<endl;

    return 0;
}
