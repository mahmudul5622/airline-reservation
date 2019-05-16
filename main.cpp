    #include <iostream>
    #include <windows.h>
    #include <mysql.h>
    #include <stdlib.h>
    #include <sstream>
    using namespace std;
    int ch,qstate;
    char ch2='y';
    string username = "admin", password = "admin";
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;

    COORD c;
    void gotoxy(int x, int y)
    {
        c.X=x;
        c.Y=y;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    }

    class Airline
    {
        string id,flight_type,date,month,year,source,destination,flight_no,ref_no,time,ticket,fname,mname,lname,passport,district,city,phone,email,nationality,gender,pass;
        string fly_id,fly_type,d,m,y,sou,des,fly_no,re,ti,tick;

    public:
        void register_customer()
        {
            system("cls");
                gotoxy(45,1); cout<<"------------------------------"<<endl;
                gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
                gotoxy(45,3); cout<<"------------------------------"<<endl;
                gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                gotoxy(10,7); cout<<"First Name : ";
                gotoxy(40,7); cout<<"Middle Name : ";
                gotoxy(70,7); cout<<"Last Name : ";
                gotoxy(10,9); cout<<"Birth date...";
                gotoxy(10,10); cout<<"Date : ";
                gotoxy(30,10); cout<<"Month : ";
                gotoxy(50,10); cout<<"Year : ";
                gotoxy(10,12); cout<<"Passport No(P0000000) : ";
                gotoxy(10,14); cout<<"District : ";
                gotoxy(45,14); cout<<"City : ";
                gotoxy(10,16); cout<<"Phone No : ";
                gotoxy(10,18); cout<<"E-mail : ";
                gotoxy(10,20); cout<<"Nationality : ";
                gotoxy(10,22); cout<<"Gender(M/F) : ";
                gotoxy(10,24); cout<<"Password : ";
                gotoxy(0,26); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                gotoxy(25,7); cin>>fname;
                gotoxy(55,7); cin>>mname;
                gotoxy(85,7); cin>>lname;
                gotoxy(20,10); cin>>date;
                gotoxy(40,10); cin>>month;
                gotoxy(60,10); cin>>year;
                gotoxy(40,12); cin>>passport;
                gotoxy(30,14); cin>>district;
                gotoxy(65,14); cin>>city;
                gotoxy(30,16); cin>>phone;
                gotoxy(30,18); cin>>email;
                gotoxy(30,20); cin>>nationality;
                gotoxy(30,22); cin>>gender;
                gotoxy(30,24); cin>>pass;

               string query="insert into customer(firstname,middlename,lastname,date,month,year,passport,district,city,phone,email,nationality,gender,password) values('"+fname+"','"+mname+"','"+lname+"','"+date+"','"+month+"','"+year+"','"+passport+"','"+district+"','"+city+"','"+phone+"','"+email+"','"+nationality+"','"+gender+"','"+pass+"')";

                                const char* q = query.c_str(); // c++ string are converted to c string(c.str())

                                qstate = mysql_query(conn,q);

                                if(!qstate){
                                    gotoxy(40,27); cout<<"You are successfully Registered.."<<endl;
                                    system("pause");
                                }
                                else{
                                    gotoxy(40,27); cout<<"query problem: "<<mysql_error(conn)<<endl;
                                    system("pause");
                                }
                                system("cls");

        }
        void login_customer()
        {
            system("cls");
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(50,5); cout<<"------------------"<<endl;
            gotoxy(50,6); cout<<"| Customer Login |"<<endl;
            gotoxy(50,7); cout<<"------------------"<<endl;
            gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(35,11); cout<<"E-mail : ";
            gotoxy(35,13); cout<<"Password : ";
            gotoxy(0,15); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(50,11); cin>>email;
            gotoxy(50,13); cin>>pass;

            qstate = mysql_query(conn,"select * from customer_flight");

                if(!qstate)
                {
                    res = mysql_store_result(conn);
                    while(row = mysql_fetch_row(res))
                    {
                        if(email == row[6] && pass == row[9])
                        {
                            system("cls");
                            gotoxy(45,1); cout<<"------------------------------"<<endl;
                            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
                            gotoxy(45,3); cout<<"------------------------------"<<endl;
                            gotoxy(44,5); cout<<"-------------------------------"<<endl;
                            gotoxy(44,6); cout<<"| Customer and Flight Details |"<<endl;
                            gotoxy(44,7); cout<<"-------------------------------"<<endl;
                            gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                            gotoxy(45,10); cout<<"<----Personal Details---->";
                            gotoxy(5,12); cout<<"Full Name :- "<<row[1]<<".";
                            gotoxy(40,12); cout<<"Birth date :- "<<row[2]<<".";
                            gotoxy(75,12); cout<<"E-mail :- "<<row[6]<<".";
                            gotoxy(5,14); cout<<"Address :- "<<row[4]<<".";
                            gotoxy(40,14); cout<<"Phone No :- "<<row[5]<<".";
                            gotoxy(75,14); cout<<"Passport :- "<<row[3]<<".";
                            gotoxy(25,16); cout<<"Nationality :- "<<row[7]<<".";
                            gotoxy(70,16); cout<<"Gender :- "<<row[8]<<".";
                            gotoxy(47,18); cout<<"<----Flight Details---->";
                            gotoxy(5,20); cout<<"flight Type :- "<<row[10]<<".";
                            gotoxy(40,20); cout<<"Tour Date :- "<<row[11]<<".";
                            gotoxy(75,20); cout<<"Destination :- "<<row[12]<<".";
                            gotoxy(5,22); cout<<"Flight No :- "<<row[13]<<".";
                            gotoxy(30,22); cout<<"Reference No :- "<<row[14]<<".";
                            gotoxy(65,22); cout<<"Time :- "<<row[15];
                            gotoxy(85,22); cout<<"Ticket :- "<<row[16];
                            gotoxy(0,24); cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                        }
                        else
                        {
                            gotoxy(45,16); cout<<"Invalid Email/Password..."<<endl;
                        }
                    }
                }

        }
        void admin_login()
        {
                gotoxy(45,1); cout<<"------------------------------"<<endl;
                gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
                gotoxy(45,3); cout<<"------------------------------"<<endl;
                gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                gotoxy(40,9); cout<<"USERNAME : ";
                gotoxy(40,11); cout<<"PASSWORD : ";
                gotoxy(0,14); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                gotoxy(55,9); cin>>username;
                gotoxy(55,11); cin>>password;

        }
        void book_flight()
        {
            string date1,month1,year1,destination1;
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(10,7); cout<<"Date of tour...";
            gotoxy(10,8); cout<<"Date : ";
            gotoxy(30,8); cout<<"Month : ";
            gotoxy(50,8); cout<<"Year : ";
            gotoxy(10,10); cout<<"Destination : ";
            gotoxy(0,12); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(20,8); cin>>date1;
            gotoxy(40,8); cin>>month1;
            gotoxy(60,8); cin>>year1;
            gotoxy(40,10); cin>>destination1;

            qstate = mysql_query(conn,"select * from flight");

                if(!qstate)
                        {
                            system("cls");
                            cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                            cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                            cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                            res = mysql_store_result(conn);
                            while(row=mysql_fetch_row(res))
                            {
                                if(destination1 == row[5] && date1 == row[2] && month1 == row[3] && year1 == row[4]){
                                    cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                    cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                }
                            }

                        }
                        else
                        {
                            cout<<"query error: "<<mysql_error(conn)<<endl;
                        }

        }
        void merge_customer_flight()
        {
            cout<<"If You Want To Book A flight Please Select Flight ID : "; cin>>id;
            system("cls");
            cout<<"Selected flight is below..."<<endl;
                            qstate = mysql_query(conn,"select * from flight");

                if(!qstate)
                        {
                            cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                            cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                            cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                            res = mysql_store_result(conn);
                            while(row=mysql_fetch_row(res))
                            {
                                if(id == row[0]){
                                    cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                    cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                    fly_id = row[0];
                                    fly_type = row[1];
                                    d = row[2];
                                    m = row[3];
                                    y = row[4];
                                    des = row[5];
                                    fly_no = row[6];
                                    re = row[7];
                                    ti = row[8];
                                    tick = row[9];
                                    string query="insert into customer_flight(full_name,birth_date,passport,address,phone,email,nationality,gender,password,flight_type,tour_date,destination,flight_no,ref_no,time,ticket) values('"+fname+" "+mname+" "+lname+"','"+date+"/"+month+"/"+year+"','"+passport+"','"+district+", "+city+"','"+phone+"','"+email+"','"+nationality+"','"+gender+"','"+pass+"','"+fly_type+"','"+d+"/"+m+"/"+y+"','"+des+"','"+fly_no+"','"+re+"','"+ti+"','"+tick+"')";

                                const char* q = query.c_str(); // c++ string are converted to c string(c.str())
                                cout<<"Query is : "<<q<<endl;

                                qstate = mysql_query(conn,q);

                                if(!qstate){
                                    cout<<"You are successfully Registered.."<<endl;
                                }
                                else{
                                   cout<<"query problem: "<<mysql_error(conn)<<endl;
                                }
                                }
                            }

                        }
                        else
                        {
                            cout<<"query error: "<<mysql_error(conn)<<endl;
                        }
                        system("pause");
        }
        void flight_schedule()
        {

        }
        void add_flight()
        {
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(40,8); cout<<"1) International Flight ADD";
            gotoxy(40,11); cout<<"2) Domestic Flight ADD";
            gotoxy(0,14); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(40,17); cout<<"Choose the option : "; cin>>ch;
            system("CLS");
            switch(ch)
            {
                case 1 :    gotoxy(45,1); cout<<"------------------------------"<<endl;
                            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
                            gotoxy(45,3); cout<<"------------------------------"<<endl;
                            gotoxy(30,5); cout<<"-----------------------------------------------------------"<<endl;
                            gotoxy(30,6); cout<<"| ADMIN SECTION - ADDING INTERNATIONAL FLIGHT FROM MUMBAI |"<<endl;
                            gotoxy(30,7); cout<<"-----------------------------------------------------------"<<endl;
                            gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                            if(conn)
                            {
                                flight_type = "International";
                                gotoxy(10,11); cout<<"Date : ";
                                gotoxy(30,11); cout<<"Month : ";
                                gotoxy(50,11); cout<<"Year : ";
                                gotoxy(10,13); cout<<"To : ";
                                gotoxy(10,15); cout<<"Time(HH:mm) : ";
                                gotoxy(10,17); cout<<"Ticket : ";
                                gotoxy(10,19); cout<<"Flight No(A-000) : ";
                                gotoxy(10,21); cout<<"Reference No(REF0000000) : ";
                                gotoxy(0,23); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                                gotoxy(20,11); cin>>date;
                                gotoxy(40,11); cin>>month;
                                gotoxy(60,11); cin>>year;
                                gotoxy(20,13); cin>>destination;
                                gotoxy(30,15); cin>>time;
                                gotoxy(25,17); cin>>ticket;
                                gotoxy(35,19); cin>>flight_no;
                                gotoxy(40,21); cin>>ref_no;
                                string query="insert into flight(flight_type,date,month,year,destination,flight_no,ref_no,time,ticket) values('"+flight_type+"','"+date+"','"+month+"','"+year+"','"+destination+"','"+flight_no+"','"+ref_no+"','"+time+"','"+ticket+"')";

                                const char* q = query.c_str(); // c++ string are converted to c string(c.str())

                                qstate = mysql_query(conn,q);

                                if(!qstate){
                                    gotoxy(40,25); cout<<"Flight Added sucsessfully..."<<endl;
                                }
                                else{
                                    gotoxy(40,25); cout<<"query problem: "<<mysql_error(conn)<<endl;
                                }
                                    }
                            break;

                case 2 :    gotoxy(45,1); cout<<"------------------------------"<<endl;
                            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
                            gotoxy(45,3); cout<<"------------------------------"<<endl;
                            gotoxy(33,5); cout<<"------------------------------------------------------"<<endl;
                            gotoxy(33,6); cout<<"| ADMIN SECTION - ADDING DOMESTIC FLIGHT FROM MUMBAI |"<<endl;
                            gotoxy(33,7); cout<<"------------------------------------------------------"<<endl;
                            gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                            if(conn)
                            {
                                flight_type = "Domestic";
                                gotoxy(10,11); cout<<"Date : ";
                                gotoxy(30,11); cout<<"Month : ";
                                gotoxy(50,11); cout<<"Year : ";
                                gotoxy(10,13); cout<<"To : ";
                                gotoxy(10,15); cout<<"Time(HH:mm) : ";
                                gotoxy(10,17); cout<<"Ticket : ";
                                gotoxy(10,19); cout<<"Flight No(ABC-000) : ";
                                gotoxy(10,21); cout<<"Reference No(REF0000000) : ";
                                gotoxy(0,23); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                                gotoxy(20,11); cin>>date;
                                gotoxy(40,11); cin>>month;
                                gotoxy(60,11); cin>>year;
                                gotoxy(20,13); cin>>destination;
                                gotoxy(30,15); cin>>time;
                                gotoxy(25,17); cin>>ticket;
                                gotoxy(40,19); cin>>flight_no;
                                gotoxy(40,21); cin>>ref_no;
                                string query="insert into flight(flight_type,date,month,year,destination,flight_no,ref_no,time,ticket) values('"+flight_type+"','"+date+"','"+month+"','"+year+"','"+destination+"','"+flight_no+"','"+ref_no+"','"+time+"','"+ticket+"')";

                                const char* q = query.c_str();

                                qstate = mysql_query(conn,q);

                                if(!qstate){
                                    gotoxy(40,25); cout<<"Flight Added successfully..."<<endl;
                                }
                                else{
                                    gotoxy(40,25); cout<<"query problem: "<<mysql_error(conn)<<endl;
                                }
                                    }
                            break;

                system("pause");
            }

        }
        void customer_flight_details()
        {

        }
        void sort_by_destination()
        {
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(30,7); cout<<"Enter the destination for sorting : ";
            gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(75,7); cin>>destination;
            system("cls");

                    qstate = mysql_query(conn,"select * from flight");

                            if(!qstate)//dont know....
                            {
                                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                res = mysql_store_result(conn);
                                while(row=mysql_fetch_row(res))
                                {
                                    if(destination == row[5]){
                                        cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                        cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                    }
                                }
                                system("pause");
                            }
                            else
                            {
                                cout<<"query error: "<<mysql_error(conn)<<endl;
                            }
        }
        void sort_by_date()
        {
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(10,7); cout<<"1) 03 / 04 / 2019 "<<endl;
            gotoxy(10,9); cout<<"2) 04 / 04 / 2019 "<<endl;
            gotoxy(10,11); cout<<"3) 03 / 03 / 2019 "<<endl;
            gotoxy(0,13); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(10,15); cout<<"Select the option : "; cin>>ch;
                switch(ch)
                {
                    case 1 :    system("cls");
                                date = "1";
                                qstate = mysql_query(conn,"select * from flight");
                                if(!qstate)
                                {
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    res = mysql_store_result(conn);
                                    while(row=mysql_fetch_row(res))
                                    {
                                        if(row[2] == date)
                                        {
                                            cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                            cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                        }
                                    }
                                    system("pause");
                                }
                                else
                                {
                                    cout<<"query error: "<<mysql_error(conn)<<endl;
                                }
                                break;
                    case 2 :    system("cls");
                                date = "2";
                                qstate = mysql_query(conn,"select * from flight");

                                if(!qstate)
                                {
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    res = mysql_store_result(conn);
                                    while(row=mysql_fetch_row(res))
                                    {
                                        if(row[2] == date)
                                        {
                                            cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                            cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                        }
                                    }
                                    system("pause");
                                }
                                else
                                {
                                    cout<<"query error: "<<mysql_error(conn)<<endl;
                                }
                                break;
                    case 3 :    system("cls");
                                date = "3";
                                qstate = mysql_query(conn,"select * from flight");

                                if(!qstate)
                                {
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    cout<<"| Flight ID |  Flight Type  |      Date      | Destination |  Flight No  | Reference No | Time | Ticket |"<<endl;
                                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                                    res = mysql_store_result(conn);
                                    while(row=mysql_fetch_row(res))
                                    {
                                        if(row[2] == date)
                                        {
                                            cout<<"\t"<<row[0]<<"\t"<<row[1]<<"\t"<<row[2]<<"/"<<row[3]<<"/"<<row[4]<<"\t"<<row[5]<<"\t\t"<<row[6]<<"\t"<<row[7]<<"\t"<<row[8]<<"\t"<<row[9]<<endl;
                                            cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;
                                        }
                                    }
                                    system("pause");
                                }
                                else
                                {
                                    cout<<"query error: "<<mysql_error(conn)<<endl;
                                }
                                break;
                    default :   cout<<"Invalid Option"<<endl;
                                break;
                }
        }
    };

    class Airline_menu : public Airline
    {
    public:
        void front_menu()
        {
            system("COLOR a");
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5);
            cout<<"\t\t*----------------------------------------------------------------------*"<<endl;
            gotoxy(10,7);
            cout<<"\t*--          1) Customer Registration                                  --*"<<endl;
            gotoxy(10,9);
            cout<<"\t*--          2) Customer Login                                         --*"<<endl;
            gotoxy(10,11);
            cout<<"\t--           3) Admin Login                                             --*"<<endl;
            gotoxy(0,13);
            cout<<"\t\t*-----------------------------------------------------------------------*"<<endl;
            gotoxy(30,15); cout<<" ^_^ Please select the option = "; cin>>ch;
            system("CLS");
        }
        void admin_menu()
        {
            gotoxy(45,1); cout<<"------------------------------"<<endl;
            gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
            gotoxy(45,3); cout<<"------------------------------"<<endl;
            gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(10,7); cout<<"1) Show Flight's by Date"<<endl;
            gotoxy(10,9); cout<<"2) Show flight's by Destination"<<endl;
            gotoxy(10,11); cout<<"3) Add Flight"<<endl;
            gotoxy(0,13); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(10,15); cout<<"Select the option : "; cin>>ch;
        }
    };

    int main()
    {
        Airline_menu obj;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn,"localhost","root","","airline",0,NULL,0);

        while(ch2 == 'y' || ch2 == 'Y')
            {
            obj.front_menu();
            switch(ch)
            {
                case 1 :    obj.register_customer();
                            obj.book_flight();
                            obj.merge_customer_flight();
                            break;
                case 2 :    obj.login_customer();

                            break;
                case 3 :    obj.admin_login();
                            if(username != username && password != password)
                                    {
                                        gotoxy(30,13); cout<<"Invalid Username and Password"<<endl;
                                        gotoxy(40,16); system("pause");
                                    }
                                    else
                                    {
                                        system("CLS");
                                        obj.admin_menu();
                                        switch(ch)
                                        {
                                            case 1 :    system("cls");
                                                        obj.sort_by_date();
                                                        break;
                                            case 2 :    system("cls");
                                                        obj.sort_by_destination();
                                                        break;
                                            case 3 :    system("cls");
                                                        obj.add_flight();
                                                        break;
                                            default :   cout<<"Invalid option"<<endl;
                                                        break;
                                        }
                                    }

                        break;
            }
            cout<<"Go to the Home menu (y/n) : "; cin>>ch2;
            system("CLS");
            if(ch2 == 'n' || ch2 == 'N')
            {
                cout<<"Thank you have a great Day..^_^"<<endl;
            }
        }

        return 0;
    }
