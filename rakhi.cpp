#include<iostream>
using namespace std;
void pleaseChooseAnOption(){
    cout<<"yes(type 1)/no, i am scared(type 2)"<<endl;
    int a;
    cin>>a;
    if(a==1){
        cout<<"Great choice, keep it up"<<endl;
    }
    if(a==2){
        cout<<"Good decision, unfortunately you have no choice"<<endl;
        cout<<"Please proceed further"<<endl;
    }
}
void q1(){
    cout<<"Who is better sibling?"<<endl;
    cout<<"obviously me(type 1)/its you(type 2)"<<endl;
    int b;
    cin>>b;
    while(b==1){
        cout<<"You are not exactly right!"<<endl;
        cout<<"Please choose another option"<<endl;
        cin>>b;
    }
    if(b==2){
        cout<<"Thank you for recognising"<<endl;
    }
}
void q2(){
    cout<<"What do you want as your rakhi gift?"<<endl;
    cout<<"option1:money(type 1)"<<endl;
    cout<<"option2:chocolates(type 2)"<<endl;
    cout<<"option3:anything you want(type 3)"<<endl;
    cout<<"option4:your love(type 4)"<<endl;
    int c;
    cin>>c;
    if(c==1){
        cout<<"Not accepted. proceed further"<<endl;
    }
    if(c==2){
        cout<<"Approved! max budget:0/-"<<endl;
    }
    if(c==3){
        cout<<"Dangerous request"<<endl;
    }
    if(c==4){
        cout<<"Error: sorry its not found"<<endl;
    }
}
bool q3(){
    cout<<"Are you bored of this process?"<<endl;
    cout<<"Honest answer required no one will be hurt"<<endl;
    cout<<"slightly(type 1)/not at all(type 2)"<<endl;
    int d;
    cin>>d;
    if(d==1){
        cout<<"only some more time, please wait"<<endl;
        cout<<"and the final thing for today"<<endl;
        cout<<"Thankyou so much for spending this much time for me"<<endl;
        return true;
    }
    if(d==2){
        cout<<"Good. I was expecting you to lie anyway."<<endl;
        return false;
    }
}
void q4(){
    cout<<"If you had to choose between me and 10000/-, what would you choose?"<<endl;
    cout<<"you(type 1)/10000/-(type 2)/can i have both(type 3)"<<endl;
    int e;
    cin>>e;
    if(e==1){
        cout<<"Thank you so much anyways I know you choose wrong option"<<endl;
    }
    if(e==2){
        cout<<"Rakhi cancel enjoy your day"<<endl;
    }
    if(e==3){
        cout<<"Waste fellow"<<endl;
    }
}
void q5(){
    cout<<"After knowing me just for max 7 months, and after this much torture do you still accept me as your akka?"<<endl;
    cout<<"no really(type 1)/of course(type 2)/unfortunately yes(type 3)"<<endl;
    int f;
    cin>>f;
    if(f==1){
        cout<<"I am sorry for hurting you"<<endl;
    }
    if(f==2){
        cout<<"Thank you so much for your love"<<endl;
    }
    if(f==3){
        cout<<"It's ok no problem"<<endl;
    }
}
void q6(){
    cout<<"Do you accept that I am always right?"<<endl;
    cout<<"yes(type 1)/no(type 2)"<<endl;
    int g;
    cin>>g;
    if(g==1){
        cout<<"I knew it"<<endl;
    }
    while(g==2){
        cout<<"Sorry not accepeted, please enter another option"<<endl;
        cin>>g;
    }
}
int main(){
    cout<<"Just a comedy thing for today"<<endl;
    cout<<"Completely unnecessary test for a completely unnecessary person"<<endl;
    cout<<"Before proceeding, confirm do you want to continue?"<<endl;
    pleaseChooseAnOption();
    cout<<"Question1"<<endl;
    q1();
    cout<<"Question2"<<endl;
    q2();
    cout<<"Question3"<<endl;
    if(q3()==true){
        return 0;
    }
    cout<<"Question4"<<endl;
    q4();
    cout<<"Question5"<<endl;
    q5();
    cout<<"Question6"<<endl;
    q6();
    cout<<"CAUTION:NO AI IS USED TO MAKE THIS(EXCEPT FOR SOME OPTIONS), IT'S BY ME"<<endl;
    cout<<"Neeku ee rakhi nachuthundhi ani expect chesthunnaanu, a small thing for my thammudu"<<endl;
    cout<<"Really sorry for torturing you with this"<<endl;
    cout<<"Thankyou so much for making my rakhi this much special"<<endl;
    cout<<"Finally, Happy happy happy Rakhi thammudu"<<endl;
}