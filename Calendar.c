#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

char UIFrameMain(int color);
char UIDecade(int color);
char UIYear(int color);
char UIMonth(int color);
char UIAddEvent(int color);
char createFrame(int xFrame, int yFrame, int aFrame, int bFrame, int color);
char UIMenu2(int colorMonth, int colorYear, int colorDecade, int colorEvent, int colorGoToDate, int colorSetting);
char UIMenu1(int colorLogin, int colorRegister, int colorGuest);
int color = 10;
char UIGuest(int color);
char UILogin(int color);
char UIRegister(int color);
char UISetting(int color);


char UIGoToDate(int color);

void createAndFixNote(char *fileName);
void createAndFixNote(char *fileName);
void readNote(char *fileName);
void removeNote(char *fileName);
char *takeFileName();

int handleArrowKey(int row, int column, int n, int ele, int ch, int invalidEle, int *count);

void createBoard1();
void createBoard2();
void createBoard3();
void createBoard4();
void createBoard5();
void createBoard6();
void deleteBoard1();
void deleteBoard2();
void deleteBoard3();

void createData();

void changeColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int getday(int *startWeekDay);

void resizeConsole(int width, int height);

void SetCursorPosition(int x, int y);

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
};

int setColor();

void formatConsole(int *xp0, int *yp0, int *disx, int *disy);

void getNumberOfElements(int *n);

void getFirstHighlightedEle(int n, int *firstEle);

void getColumn(int *col, int n);

int *getSpecialDays(int invalidEle, int n, int specColor, int *day);

void UImenu(int *count);
void UI01(int *count);
void UI02(int *count);
void UI03(int *count);
void UILoginMenu();

void dayNow(int *thisDay, int *thisMonth, int *thisYear);
void dayNowShow();
int flag = 0;
int thisD,thisM,thisY;

void getDataPreMonth();

struct tm data[106000][7];
char chA = 218, chB = 191, chC = 192, chD = 217, chE = 196, chF = 179, chG = 214, chH = 186, chI = 211, chJ = 210, chK = 189;

typedef struct
{
    int startI;
    int startJ;
    int month;
    int year;
    int decade;
} data02;
data02 dataforPreMonth[700];
int countOut = 0;
int iStart = 103259, jStart = 1, monthToShow = 1, yearToShow = 1980, decadeToShow = 202; //ngay tao data nam 2000
int startingDay = 7;
int startingMonth = 3;
int startingYear = 1;
int preChosenDay = 9; //Ngay hien tai

int state = 100;
int stateFlag = 1;
int saveState = 0;
int stateOfMenu = 100;
int addNoteFlag = 1;
int removeNoteFlag = 1;
int readNoteFlag = 1;
int menuFlag = 1;
int goToDateFlag = 1;
int DateOfGTD = 100;

int UIMenuFlag = 1;
int state1 = 100;
int stateOfMenu1 = 100;
int saveState1 = 1;
int stateFlag1 = 1;
int exitFlag = 0;
int logOutFlag = 0;
int quitFlag = 0;

int pos;
int loginFlag = 0;
char username[100];
char userFileNote[100];
char checkNote[100];

char *months[] = {
    " ",
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"};

int main()
{
    resizeConsole(540, 580);
    int ch;
    createData();
    //printf("%d %d %d", data[iStart][jStart].tm_mday,data[iStart][jStart].tm_mon,data[iStart][jStart].tm_year);
    //getch();

    while (data[iStart][jStart].tm_year < 2033) //tao data toi nam
        getDataPreMonth();

    dayNow(&thisD, &thisM, &thisY);
    //printf("%d",thisM);

    int count;
    int m = 100;
    for (m; m < 700; m++)
        if (dataforPreMonth[m].year == thisY)
        {
            for (m; m < 700; m++)
                if (dataforPreMonth[m].month == thisM)
                {
                    count = m;
                    break;
                }
            break;
        }


while(1)
{

    while (UIMenuFlag == 1)
    {
        
        while (state1 == stateOfMenu1)
        {      
            dayNowShow();
            UILoginMenu();
            //gotoxy(2,35);
            //printf("test");
        }
        
        

        if (state1 == 1)
        {
            loginFlag = 0;
            UILogin(02);
            createFrame(3, 8, 12, 2, 7);
            createUserName();
            saveState1 = 1;
        }

        if (state1 == 2)
        {
            UIRegister(02);
            createFrame(3, 11, 12, 2, 7);
            registerUserR();
            saveState1 = 2;
        }

        if (state1 == 3)
        {
            UIGuest(02);
            saveState1 = 3;
        }

        if (state1 == 4)
        {
            saveState1 = 4;
            UIFrameMain(10);
            UIMenu1(7, 7, 7);
            createFrame(3, 17, 12, 2, 7);
            gotoxy(7, 18);
            changeColor(2);
            printf("Exit");
            changeColor(7);
            gotoxy(24, 11);
            printf("THANK YOU FOR USING OUR CALENDAR!");
            gotoxy(27, 12);
            printf("DO YOU REALLY WANT TO QUIT?");
            gotoxy(20, 13);
            printf("Use 'enter' to QUIT, other keys to CANCEL");
            gotoxy(0, 0);
            int opt;
            fflush(stdin);
            while (opt = getch())
            {
                fflush(stdin);

                if (opt == 13)
                {
                    exitFlag = 1;
                    exit(0);
                }
                else
                {
                    gotoxy(24, 11);
                    printf("                                    ");
                    gotoxy(27, 12);
                    printf("                                 ");
                    gotoxy(20, 13);
                    printf("                                         ");
                    saveState1 = 4;
                    break;
                }
            }
        }

        saveState1 = state1;
        state1 = stateOfMenu1;

        if (loginFlag ==1)
            UIMenuFlag = 0;    
    }


    
    while (1)
    {
        UIFrameMain(02);
        while (state == stateOfMenu)
        {
            dayNowShow();
            UImenu(&count);
        }
        stateFlag = 0;

        UIFrameMain(02);
        while (state == 2)
        {
            UIDecade(2);
            createFrame(2, 14, 14, 2, 7);
            dayNowShow();
            UI03(&count);
        }
        system("cls");

        UIFrameMain(02);
        while (state == 1)
        {
            UIYear(2);
            createFrame(2, 11, 14, 2, 7);
            dayNowShow();
            UI02(&count);
        }
        system("cls");

        UIFrameMain(02);
        while (state == 0)
        {
           
            UIMonth(2);
            createFrame(2, 8, 14, 2, 7);
            dayNowShow();
            UI01(&count);
        }

        if (state == 5)
        {
                    UIMenu2(7,7,7,7,7,10);
                    //createFrame(2, 23, 14, 2, 10);
                    UISetting(10);
                    createFrame(2, 23, 14, 2, 7);
                    //goto(20,12);
                    //printf("HAVE A GOOD DAY")
                    gotoxy(20, 15);
                    printf("Press 1 to LOG OUT                     ");
                    gotoxy(20, 16);
                    printf("Press 2 to CLOSE THE APP                ");
                    gotoxy(20, 17);
                    printf("Press other key to GET BACK to MENU     ");
                    fflush(stdin);
                    char option = getch();
                    fflush(stdin);
                    switch(option)
                    {
                        case '1': {
                            logOutFlag = 1;
                            saveState = 0;
                            state = stateOfMenu;
                            break;
                        }
                        case '2': {
                            quitFlag = 1;
                            saveState = 0;
                            state = stateOfMenu;
                            break;
                        }
                        default:{
                            state = stateOfMenu;
                            saveState = 5;
                        }

                    }
        }

        system("cls");
        if (logOutFlag == 1)
        {
            logOutFlag = 0;
            UIMenuFlag =1;
            saveState1 = 1;
            state1 = stateOfMenu1;
            
            strcpy(username,"");
            break;
        }
        if (quitFlag == 1)
        {
            quitFlag = 0;
            UIMenuFlag = 1;
            state1 = 4;
            break;
        }
        
    }
    
    }
}
void UILoginMenu()
{
    system("cls");
    stateFlag1 = 1;
    switch (saveState1)
    {
    case 1:
    {
        UILogin(02);
        break;
    }
    case 2:
    {
        UIRegister(02);
        break;
    }
    case 3:
    {
        
        UIGuest(02);
        break;
    }
    case 4:
    {

        UIFrameMain(02);
        UIMenu1(7, 7, 7);
        createFrame(3, 17, 12, 2, 2);
        changeColor(2);
        gotoxy(7, 18);
        printf("Exit");
        changeColor(7);
    }
    }
    state1 = saveState1;
    int ch;
    while ((ch = _getch()) != 27)
    {
        if (ch == 0 || ch == 224)
        {
            switch (ch = _getch())
            {
            case 72:
            {
                if (state1 > 1) //len
                    state1 -= 1;
                break;
            }
            case 80:
            {
                if (state1 < 4) //DI XUONG
                    state1 += 1;
                break;
            }
            }
            if (ch == 72 || ch == 80)
            {
                system("cls");
                switch (state1)
                {
                case 1:
                {
                    
                    UILogin(02);
                    break;
                }
                case 2:
                {
                    UIRegister(02);
                    break;
                }
                case 3:
                {
                    UIGuest(02);
                    int d, m, y, i;
                    dayNow(&d, &m, &y);
                    stateFlag = 0;
                    for (i = 0; i < 700; i++)
                    {
                        if (dataforPreMonth[i].year == y)
                            break;
                    }
                    i = i + m - 1;
                    flag = 0;
                    stateFlag = 1;
                    UI01(&i);
                    UIGuest(02);
                    stateFlag = 0;
                    break;
                }
                case 4:
                {
                    UIFrameMain(02);
                    UIMenu1(7,7,7);
                    createFrame(3, 17, 12, 2, 2);
                    changeColor(2);
                    gotoxy(7, 18);
                    printf("Exit");
                    changeColor(7);
                    //state1 = 4;
                    break;
                }
               
                }
                
            }

        }
        if (ch == 13)
            {
                
                //gotoxy(0,0)
                //printf("state1%d"state1);
                //getch();
                break;
            }
    }
               
}

void UImenu(int *count)
{
    system("cls");
    MENU:
    stateFlag = 1;
    switch (saveState)
    {
    case 0:
    {
        UIMonth(02);
        UI01(count);
        break;
    }
    case 1:
    {
        UIYear(02);
        UI02(count);
        break;
    }
    case 2:
    {
        UIDecade(02);
        UI03(count);
        break;
    }
    case 3:
    {
        createFrame(2, 17, 14, 2, 10);
        UIAddEvent(02);
        SetCursorPosition(22, 18);
        printf("Press enter to use NOTE features...");
        //createAndFixNote(takeFileName());
        break;
    }
    case 4:
    {
        createFrame(2, 20, 14, 2, 10);
        UIGoToDate(02);
        gotoxy(20, 28);
        printf("Press 'enter' to view a specific day   ");
        break;
    }
    case 5:
    {
        UISetting(02);
        break;
    }
    }
    state = saveState;
    int ch;
    while ((ch = _getch()) != 27)
    {
        if (ch == 0 || ch == 224)
        {
            switch (ch = _getch())
            {
            case 72:
            {
                if (state > 0) //len
                    state -= 1;
                break;
            }
            case 80:
            {
                if (state < 5) //DI XUONG
                    state += 1;
                break;
            }
            }
            if (ch == 72 || ch == 80)
            {
                system("cls");
                switch (state)
                {
                case 0:
                {
                    UIMonth(02);
                    UI01(count);
                    break;
                }
                case 1:
                {
                    UIYear(02);
                    UI02(count);
                    break;
                }
                case 2:
                {
                    UIDecade(02);
                    UI03(count);
                    break;
                }
                case 3:
                {
                    UIAddEvent(02);
                    /*
                    SetCursorPosition(22, 15);
                    printf("Press 'a' to create note");
                    SetCursorPosition(22, 16);
                    printf("Press 'x' to delete note ");
                    SetCursorPosition(22, 17);
                    printf("Press 'r' to read full note ");
                    */
                    SetCursorPosition(22, 18);
                    printf("Press enter to use NOTE features...");
                    menuFlag = 0;
                    //int char3;
                    fflush(stdin);
                    //char3 = getch();
                    fflush(stdin);
                    //menuFlag = (char3 == 13 ? 0 : 1);
                    while (menuFlag == 1)
                    {
                        EVENT:
                        menuFlag=1;
                        char but;
                        UIAddEvent(02);
                        createFrame(2, 17, 14, 2, 7);
                        SetCursorPosition(22, 15);
                        printf("Press 'a' to create note");
                        SetCursorPosition(22, 16);
                        printf("Press 'x' to delete note ");
                        SetCursorPosition(22, 17);
                        printf("Press 'r' to read full note ");
                        SetCursorPosition(22, 18);
                        printf("Press other keys to get back to menu ");
                        fflush(stdin);
                        but = _getch();
                        SetCursorPosition(22, 15);
                        printf("                                     ");
                        SetCursorPosition(22, 16);
                        printf("                                     ");
                        SetCursorPosition(22, 17);
                        printf("                                     ");
                        SetCursorPosition(22, 18);
                        printf("                                     ");
                        switch (but)
                        {

                        case ('a'):
                        {
                            while (addNoteFlag == 1)
                            {
                                gotoxy(21, 4);
                                printf("ADD NOTE     ");
                                createAndFixNote(takeFileName());
                                int i = 0;
                                for (i; i < 17; i++)
                                {
                                    SetCursorPosition(22, 9 + i);
                                    printf("                                     ");
                                }
                                SetCursorPosition(20, 24 + 4);
                                changeColor(7);
                                printf("                                         ");
                                SetCursorPosition(20, 24 + 5);
                                printf("                                          ");
                                SetCursorPosition(21, 5);
                                printf("                                   ");
                                SetCursorPosition(21, 6);
                                printf("             ");
                                SetCursorPosition(21, 7);
                                printf("             ");
                            }
                            addNoteFlag = 1;
                            SetCursorPosition(0, 0);
                            //printf("Button: %c", but);
                            break;
                        }
                        case ('x') :
                        {
                            while (removeNoteFlag == 1)
                            {
                                gotoxy(21, 4);
                                printf("DELETE NOTE     ");
                                removeNote(takeFileName());
                                int i = 0;
                                for (i; i < 17; i++)
                                {
                                    SetCursorPosition(22, 9 + i);
                                    printf("                                     ");
                                }
                                SetCursorPosition(20, 24 + 4);
                                changeColor(7);
                                printf("                                         ");
                                SetCursorPosition(20, 24 + 5);
                                printf("                                          ");
                                SetCursorPosition(21, 5);
                                printf("                                         ");
                                SetCursorPosition(21, 6);
                                printf("             ");
                                SetCursorPosition(21, 7);
                                printf("             ");
                            }
                            removeNoteFlag = 1;
                            SetCursorPosition(0, 0);
                            break;   
                        } 
                        case ('r') :{
                            while (readNoteFlag == 1)
                            {
                                gotoxy(21, 4);
                                printf("READ NOTE     ");
                                readNote(takeFileName());
                                int i = 0;
                                for (i; i < 17; i++)
                                {
                                    SetCursorPosition(22, 9 + i);
                                    printf("                                     ");
                                }
                                SetCursorPosition(20, 24 + 4);
                                changeColor(7);
                                printf("                                         ");
                                SetCursorPosition(20, 24 + 5);
                                printf("                                          ");
                                SetCursorPosition(21, 5);
                                printf("                                         ");
                                SetCursorPosition(21, 6);
                                printf("             ");
                                SetCursorPosition(21, 7);
                                printf("             ");
                            }
                            readNoteFlag = 1;
                            SetCursorPosition(0, 0);
                            break;   
                        }
                        default:   {
                            menuFlag = 0;
                            fflush(stdin);
                            break;
                        }
                        }
                    }
                    gotoxy(21, 4);
                    printf("                       ");
                    gotoxy(0,0);
                    state = 3;
                    fflush(stdin);
                    break;
                }
                case 4:
                {
                    UIGoToDate(02);
                    createFrame(2, 20, 14, 2, 10);
                    gotoxy(20, 28);
                    printf("Press 'enter' to view a specific day   ");
                    
                    //gotoxy(20, 29);
                    //printf("Press other keys to get back to menu...");
                    //char char2;
                    fflush(stdin);
                    //char2 = getch();
                    fflush(stdin);
                    //goToDateFlag = (char2 == ' ' ? 1 : 0);
                    int checker=0;
                    goToDateFlag = 0;
                    while (goToDateFlag ==1 )
                    {
                        GOTODATE:
                        goToDateFlag = 1;
                        createFrame(2, 20, 14, 2, 7);
                        UIGoToDate(02);
                        int day, month, year, i, insideCount;
                        do
                        {
                            if (checker == 1)
                            {
                                SetCursorPosition(22, 24);
                                changeColor(64);
                                printf("Enter again\n");
                                changeColor(7);
                                SetCursorPosition(22, 25);
                                printf("                              ");
                                
                            }
                        createFrame(2, 20, 14, 2, 7);
                            gotoxy(22, 25);
                            day = takeDay();
                            fflush(stdin);
                            gotoxy(30, 25);
                            month = takeMonth();
                            fflush(stdin);
                            gotoxy(40, 25);
                            year = takeYear();
                            fflush(stdin);

                            checker = 1;
                        } while (!valid(day, month, year));
                        checker = 0;
                        gotoxy(22, 24);
                        printf("            ");

                        for (i = 0; i < 700; i++)
                            if (dataforPreMonth[i].year == year)
                            {
                                insideCount = i;
                                break;
                            }

                        insideCount += month - 1;
                        DateOfGTD = 100;
                        DateOfGTD += day;
                        UI01(&insideCount);
                        createFrame(2, 20, 14, 2, 7);
                        gotoxy(20, 28);
                        printf("Press 'space' to go to another day     ");
                        gotoxy(20, 29);
                        printf("Press other keys to get back to menu...");
                        fflush(stdin);
                        char char1 = getch();
                        fflush(stdin);
                        if (char1 != ' ')
                        {
                            goToDateFlag = 0;
                            gotoxy(22, 26);
                            printf("                   ");
                            gotoxy(22, 27);
                            printf("                   ");
                            gotoxy(22, 25);
                            printf("                                         ");
                            gotoxy(20, 29);
                            printf("                                         ");
                            gotoxy(20, 28);
                            printf("                                         ");
                            gotoxy(0,0);
                        }
                        else
                        {
                            gotoxy(22, 26);
                            printf("                   ");
                            gotoxy(22, 27);
                            printf("                   ");
                            gotoxy(22, 25);
                            printf("                                              ");
                            gotoxy(0,0);
                        }
                        
                    }
                    break;
                    
                }
                case 5:
                {
                    //UISetting(02);
                    UIMenu2(7,7,7,7,7,10);
                    UISetting(02);
                    gotoxy(20, 21);
                    printf("        Press enter for settings");
                    gotoxy(0,0);
                    break;
                }
                }
                }
            }
            else if (ch == 13)
            {
                if (state == 3)
                    goto EVENT;
                if (state == 4)
                    goto GOTODATE;
                break;
            }
    }
}

void getDataPreMonth()
{

    int decade = 197;
    int t = 0;
    for (t; t < 700; t++)
    {
        if (dataforPreMonth[t].year % 10 == 0 && dataforPreMonth[t].month == 1)
        {
            decade++;
        }
        dataforPreMonth[t].decade = decade;
    }

    typedef struct
    {
        int day;

    } Coor;

    if (monthToShow > 12)
    {
        monthToShow = 1;
        yearToShow += 1;
    }

    //printf("\nYear to show %d", data[iStart][jStart].tm_year);
    //printf("\nmonth to show %d\n---------", monthToShow);

    int n; // so phan tu
    if (monthToShow == 1 || monthToShow == 3 || monthToShow == 5 || monthToShow == 7 || monthToShow == 8 || monthToShow == 10 || monthToShow == 12)
        n = 31;
    else if (monthToShow == 2)
        n = 28 + isLeapYear(data[iStart][jStart].tm_year);
    else
        n = 30;

    int invalidEle = ((jStart < 7) ? (jStart + 1) : jStart); // vi tri bat dau (1=Monday 2= Tuesday ...)

    int total = n + invalidEle;

    Coor Pos[total];

    int temp = 1;

    int column = 7; // (so phan tu 1 hang)

    int row = ((total % column == 0) ? (total / column) : ((total / column) + 1)); // so phan tu 1 cot

    //Lay lich tu data
    int ztemp = invalidEle;
    int countRow = 0;
    int countColumn = 0;
    while (jStart + countColumn <= 6)
    {
        Pos[ztemp].day = data[iStart][jStart + countColumn].tm_mday;
        ztemp++;
        countColumn++;
    }

    //dong con lai
    countRow = 1;
    while (data[iStart + countRow][0].tm_mon == monthToShow) //tuan tiep theo van trong thang
    {
        for (countColumn = 0; countColumn < 7; countColumn++) //nhung tuan tiep theo
        {
            if (data[iStart + countRow][countColumn].tm_mon == monthToShow) // phan tu trong thang
            {
                Pos[ztemp].day = data[iStart + countRow][countColumn].tm_mday;
                ztemp++;
            }
            else
                break;
        }
        if (data[iStart + countRow][countColumn].tm_mon == monthToShow)
            countRow++;
        else
            break;
    }

    dataforPreMonth[countOut].startI = iStart;
    dataforPreMonth[countOut].startJ = jStart;
    dataforPreMonth[countOut].month = monthToShow;
    dataforPreMonth[countOut].year = yearToShow;
    //printf("count: %d, month: %d\n", count, dataforPreMonth[count].month);
    countOut++;

    //NextMonth
    iStart += countRow;
    jStart = countColumn;
    monthToShow++;
}
void UI03(int *count)
{
    switch (*count / 120)
    {
    case 0:
    {
        *count = 0;
        break;
    }
    case 1:
    {
        *count = 120;
        break;
    }
    case 2:
    {
        *count = 240;
        break;
    }
    case 3:
    {
        *count = 360;
        break;
    }
    case 4:
    {
        *count = 480;
        break;
    }
    case 5:
    {
        *count = 600;
        break;
    }
    }
    if (*count < 0)
        *count = 0;
    if (*count > 600)
        *count = 600;
    typedef struct
    {
        int state;
        int yP;
        int xP;
        int year;

    } Coor;

    yearToShow = dataforPreMonth[*count].year;
    decadeToShow = dataforPreMonth[*count].decade;

    int saveCount = *count;
    //printf("\nUI03count %d", *count);

    SetCursorPosition(21, 4);
    printf("Decade to show %d0s", decadeToShow);

    int n = 10;

    int invalidEle = 0; // vi tri bat dau (1=Monday 2= Tuesday ...)

    //getNumberOfElements (&n);

    //getFirstHighlightedEle (n, &firstEle);

    int total = n + 1;

    Coor Pos[total];
    Pos[0].xP = 12;        //can le ngang
    Pos[0].yP = 8;         //can le doc
    int coorY = Pos[0].yP; // can le doc

    int disx = 10; // khoang cach cot
    int disy = 5;  // khoang cach hang

    //formatConsole (&Pos[0].xP, &Pos[0].yP, &disx, &disy);

    int i = 1, j = 1, ele = 1;
    int temp = yearToShow - yearToShow % 10;

    int column = 4; // (so phan tu 1 hang)

    //getColumn (&column, n);

    int row = ((total % column == 0) ? (total / column) : ((total / column) + 1)); // so phan tu 1 cot
    //printf("col=%d row=%d",column,row);

    // o sang dau tien
    int firstEle = startingYear;

    //Xuat lich theo nam

    for (i; i <= row; i++)
    {

        for (j = 1; j <= column; j++)
        {
            Pos[ele].xP = Pos[0].xP + disx * j;
            Pos[ele].yP = coorY;
            Pos[ele].year = temp++;
            //Pos[ele].state = 0;

            SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP - 2);
            createBoard4();
            SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP - 1);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP + 1);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP + 2);
            createBoard6();
            SetCursorPosition(Pos[ele].xP, Pos[ele].yP);
            printf("%d", Pos[ele].year); //sua o

            ele++;
            if (ele > n)
                break;
        }
        if (ele > n)
            break;
        coorY += disy;
    }

    // Change color

    int hlColor = 112;  // mau ngay duoc chon
    int specColor = 7; // mau ngay dac biet


    //hightlighted days:
    int o = 0;
    int day = 1;
    int temper;
    int hlDay[1] = {1};
    for (temper = 1;temper<=10;temper++)
        {
            if(Pos[temper].year == thisY)
            {
                hlDay[0]=temper;
                specColor = 2;
                break;
            }
        }
    //int* hlDay = getSpecialDays( invalidEle,  n,  specColor, &day);


    for (o; o < day; o++)
    {
        changeColor(specColor);
        SetCursorPosition(Pos[hlDay[o]].xP, Pos[hlDay[o]].yP);
        printf("%d", Pos[hlDay[o]].year);
        changeColor(7);
    }

    //first element
    changeColor(hlColor);
    SetCursorPosition(Pos[firstEle].xP, Pos[firstEle].yP);
    printf("%d", Pos[firstEle].year);
    changeColor(7);
    SetCursorPosition(0, 4);

    if (stateFlag == 0)
    {
        gotoxy(4, 31);
        printf("*Enter to Year");
        //handle arrow key
        int preEle = firstEle;
        int newEle = -1;
        int ch;
        fflush(stdin);
        while ((ch = _getch())) //27 = Esc key
        {
            if (ch == 27)
            {
                state = stateOfMenu;
                saveState = 2;
                break;
            }
            if (ch != 13)
            {
                if (ch == 0 || ch == 224)
                {
                    ch = _getch();

                    newEle = handleArrowKey(row, column, 11, preEle, ch, 1, count);
                    if (saveCount != *count)
                    {
                        *count = ((saveCount > *count) ? (*count = (*count + 1) - 120) : (*count = (*count - 1) + 120));
                        //printf("decadeCount: %d\n", *count);
                        startingYear = ((newEle >= 7) ? ((newEle >= 9) ? newEle - 8 : newEle - 4) : ((newEle <= 2) ? newEle + 8 : newEle + 4));
                        newEle = -1;
                        break;
                        //getch();
                    }
                    else

                        //clear previous
                        if (newEle != preEle)
                    {
                        changeColor(7);
                        SetCursorPosition(Pos[preEle].xP, Pos[preEle].yP);
                        printf("%d", Pos[preEle].year);
                        SetCursorPosition(0, 10);
                        //printf("PreE %d NewE %d Total %d", preEle, newEle, total);
                    }

                    //recolor special days
                    for (o = 0; o < day; o++)
                    {
                        if (preEle == hlDay[o])
                        {
                            changeColor(specColor);
                            SetCursorPosition(Pos[hlDay[o]].xP, Pos[hlDay[o]].yP);
                            printf("%d", Pos[hlDay[o]].year);
                            changeColor(7);
                        }
                    }
                    preEle = newEle;

                    //color current
                    if (newEle >= invalidEle)
                    {
                        changeColor(hlColor);
                        SetCursorPosition(Pos[newEle].xP, Pos[newEle].yP);
                        printf("%d", Pos[preEle].year);
                        changeColor(7);
                        SetCursorPosition(0, 5);
                    }
                }
            }
            else
            {
                state = 1;
                if (newEle != -1 && newEle)
                    *count = *count + (newEle - 1) * 12;
                else
                {
                    *count = *count + (startingYear - 1) * 12;
                }
                break;
            }
        }
    } //If
}

void UI02(int *count)
{
    

    if (*count >= 630 || *count <= 0)
        *count = ((*count >= 630) ? (*count = 630) : (*count = 0));
    typedef struct
    {
        int state;
        int yP;
        int xP;
        int month;

    } Coor;

    *count -= *count % 12;
    //printf("\ncount %d", *count);
    //*count = *count - *count%12 ;
    //flag = 0;
    //printf("\ncount %d", *count);
    //monthToShow = dataforPreMonth[*count].month;
    yearToShow = dataforPreMonth[*count].year;

    int saveCount = *count;

    SetCursorPosition(21, 4);
    printf("%d0s, %d", dataforPreMonth[*count].decade, yearToShow);

    int n = 12;

    int invalidEle = 0; // vi tri bat dau (1=Monday 2= Tuesday ...)

    //getNumberOfElements (&n);

    //getFirstHighlightedEle (n, &firstEle);

    int total = n + 1;

    Coor Pos[total];
    Pos[0].xP = 11;        //can le ngang
    Pos[0].yP = 8;         //can le doc
    int coorY = Pos[0].yP; // can le doc

    int disx = 10; // khoang cach cot
    int disy = 5;  // khoang cach hang

    //formatConsole (&Pos[0].xP, &Pos[0].yP, &disx, &disy);

    int i = 1, j = 1, ele = 1;
    int temp = 1;

    int column = 4; // (so phan tu 1 hang)

    //getColumn (&column, n);

    int row = ((total % column == 0) ? (total / column) : ((total / column) + 1)); // so phan tu 1 cot
    //printf("col=%d row=%d",column,row);

    // o sang dau tien
    //printf("\nMonth %d, count %d",dataforPreMonth[*count].month, *count);
    int firstEle = startingMonth;

    // printf("success");

    //	printf("%s", months[1]);

    //Xuat lich theo thang

    for (i; i <= row; i++)
    {

        for (j = 1; j <= column; j++)
        {
            Pos[ele].xP = Pos[0].xP + disx * j;
            Pos[ele].yP = coorY;
            Pos[ele].month = temp++;
            //Pos[ele].state = 0;

            SetCursorPosition(Pos[ele].xP - 1, Pos[ele].yP - 2);
            createBoard4();
            SetCursorPosition(Pos[ele].xP - 1, Pos[ele].yP - 1);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 1, Pos[ele].yP);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 1, Pos[ele].yP + 1);
            createBoard5();
            SetCursorPosition(Pos[ele].xP - 1, Pos[ele].yP + 2);
            createBoard6();
            SetCursorPosition(Pos[ele].xP, Pos[ele].yP);
            printf(" %s", months[Pos[ele].month]); //sua o

            ele++;
            if (ele > n)
                break;
        }
        if (ele > n)
            break;
        coorY += disy;
    }

    if (stateFlag == 0)
    {
        SetCursorPosition(20, 24);
        printf("                                         ");
        SetCursorPosition(20, 25);
        printf("                                         ");
        SetCursorPosition(20, 26);
        printf("                                         ");
        SetCursorPosition(20, 27);
        printf("                                         ");
        SetCursorPosition(20, 28);
        printf("                                         ");
        SetCursorPosition(20, 29);
        printf("                                         ");
        SetCursorPosition(0, 24);
        event(firstEle);
        createFrame(2, 23, 14, 2, 07);
        gotoxy(6, 24);
        printf("Setting");
        createFrame(1, 1, 16, 29, color);
        createFrame(18, 23, 43, 7, color);
    }

    // Change color

    int hlColor = 112;  // mau ngay duoc chon
    int specColor = 7; // mau ngay dac biet

    if (yearToShow == thisY)
        specColor = 2;
    //hightlighted days:
    int o = 0;
    int day = 1;
    //int* hlDay = getSpecialDays( invalidEle,  n,  specColor, &day);
    int hlDay[1];
    hlDay[0]=thisM;

    for (o; o < day; o++)
    {
        changeColor(specColor);
        SetCursorPosition(Pos[hlDay[o]].xP + 1, Pos[hlDay[o]].yP);
        printf("%s", months[Pos[hlDay[o]].month]);
        changeColor(7);
    }

    //first element
    changeColor(hlColor);
    SetCursorPosition(Pos[firstEle].xP + 1, Pos[firstEle].yP);
    printf("%s", months[Pos[firstEle].month]);
    changeColor(7);
    SetCursorPosition(0, 4);

    if (stateFlag == 0)
    {
        gotoxy(4, 31);
        printf("*Enter to Month");
        gotoxy(4, 32);
        printf("*Backspace to Year");
        //handle arrow key
        int preEle = firstEle;
        int newEle = -1;
        int ch;
        fflush(stdin);
        while ((ch = _getch())) //27 = Esc key
        {
            if (ch == 27)
            {
                state = stateOfMenu;
                saveState = 1;
                break;
            }
            if (ch == 8)
            {
                state = 2;
                startingYear = yearToShow % 10 + 1;
                //*count = ((newEle) ? *count-newEle+1 : buffer);
                //printf("count %d", *count);
                //getch();
                break;
            }
            if (ch != 13)
            {
                if (ch == 0 || ch == 224)
                {
                    ch = _getch();

                    newEle = handleArrowKey(row, column, 13, preEle, ch, 1, count);
                    if (saveCount != *count)
                    {
                        *count = ((saveCount > *count) ? ((*count + 1) - 12) : ((*count - 1) + 12));
                        startingMonth = ((newEle > 6) ? (newEle - 8) : (newEle + 8));
                        newEle = -1;
                        break;
                    }
                    else
                    {
                        //clear previous
                        if (newEle != preEle)
                        {
                            changeColor(7);
                            SetCursorPosition(Pos[preEle].xP + 1, Pos[preEle].yP);
                            printf("%s", months[Pos[preEle].month]);
                            SetCursorPosition(0, 10);
                            //printf("PreE %d NewE %d Total %d", preEle, newEle, total);
                        }

                        //recolor special days
                        for (o = 0; o < day; o++)
                        {
                            if (preEle == hlDay[o])
                            {
                                changeColor(specColor);
                                SetCursorPosition(Pos[hlDay[o]].xP + 1, Pos[hlDay[o]].yP);
                                printf("%s", months[Pos[hlDay[o]].month]);
                                changeColor(7);
                            }
                        }
                        preEle = newEle;
                        
                        SetCursorPosition(20,24);
                        printf("                                         ");
                        SetCursorPosition(20,25);
                        printf("                                         ");
                        SetCursorPosition(20,26);
                        printf("                                         ");
                        SetCursorPosition(20,27);
                        printf("                                         ");
                        SetCursorPosition(20,28);
                        printf("                                         ");
                        SetCursorPosition(20,29);
                        printf("                                         ");
                        SetCursorPosition(0,24);
                        event(newEle);
                        createFrame(2, 23, 14, 2, 07);
                        gotoxy(6, 24);
                        printf("Setting");
                        createFrame(1, 1, 16, 29, color);
                        createFrame(18, 23, 43, 7, color);
                        

                        //color current
                        if (newEle >= invalidEle)
                        {
                            changeColor(hlColor);
                            SetCursorPosition(Pos[newEle].xP + 1, Pos[newEle].yP);
                            printf("%s", months[Pos[newEle].month]);
                            changeColor(7);
                            SetCursorPosition(0, 5);
                        }
                    }
                }
            }
            else
            {
                //	printf("newEle %d\n", newEle);
                //printf("new %d first %d", newEle, firstEle);
                state = 0;
                *count = ((newEle && newEle != -1) ? *count + newEle - 1 : (*count + firstEle - 1));
                //getch();
                //	printf("count %d", *count);
                //	getch();
                //	*startingDay =25;
                break;
            }
        }
        //system("cls");
        //*startingMonth = preEle;
        //printf("pre%d new%d ", preEle, newEle);
    }
}

void UI01(int *count)
{
    
    if (*count >= 630 || *count <= 0)
        *count = ((*count >= 630) ? (*count = 630) : (*count = 0));
    typedef struct
    {
        int state;
        int yP;
        int xP;
        int day;

    } Coor;

    iStart = dataforPreMonth[*count].startI;
    jStart = dataforPreMonth[*count].startJ;
    monthToShow = dataforPreMonth[*count].month;

    int saveCount = *count;
    //printf("count001 %d", saveCount);

    SetCursorPosition(20, 2);
    printf("%s, %d", months[monthToShow], dataforPreMonth[*count].year);

    int n; // so phan tu
    if (monthToShow == 1 || monthToShow == 3 || monthToShow == 5 || monthToShow == 7 || monthToShow == 8 || monthToShow == 10 || monthToShow == 12)
        n = 31;
    else if (monthToShow == 2)
        n = 28 + isLeapYear(data[iStart][jStart].tm_year);
    else
        n = 30;

    int invalidEle = ((jStart < 7) ? (jStart + 1) : jStart); // vi tri bat dau (1=Monday 2= Tuesday ...)

    //getNumberOfElements (&n);

    //getFirstHighlightedEle (n, &firstEle);

    int total = n + invalidEle;

    Coor Pos[total];
    Pos[0].xP = 15;        //can le ngang
    Pos[0].yP = 6;         //can le doc
    int coorY = Pos[0].yP; // can le doc

    int disx = 6; // khoang cach cot
    int disy = 3; // khoang cach hang

    //formatConsole (&Pos[0].xP, &Pos[0].yP, &disx, &disy);

    int temp = 0;

    int i = 1, j = 1, ele = 1;

    int column = 7; // (so phan tu 1 hang)

    //getColumn (&column, n);

    int row = ((total % column == 0) ? (total / column) : ((total / column) + 1)); // so phan tu 1 cot
    //printf("col=%d row=%d",column,row);

    // o sang dau tien
    int firstEle = 5;
    //printf("\nstartingDay: %d", startingDay);
    if (startingDay <= 14)
        firstEle = ((startingDay < invalidEle) ? startingDay + 7 : startingDay);
    else if (startingDay - invalidEle > total - 8)
        firstEle = ((startingDay >= total) ? ((startingDay - 7 >= total) ? startingDay - 14 : startingDay - 7) : startingDay);
    else
        firstEle = startingDay;
    if (firstEle <= invalidEle || firstEle >= total)
        firstEle = 11;


    //Lay lich tu data
    int ztemp = invalidEle;
    int countRow = 0;
    int countColumn = 0;
    //dong dau trong bang
    while (jStart + countColumn <= 6)
    {
        Pos[ztemp].day = data[iStart][jStart + countColumn].tm_mday;
        ztemp++;
        countColumn++;
        //anphaTemp++;
    }

    //dong con lai
    countRow = 1;
    while (data[iStart + countRow][0].tm_mon == monthToShow) //tuan tiep theo van trong thang
    {
        for (countColumn = 0; countColumn < 7; countColumn++) //nhung tuan tiep theo
        {
            if (data[iStart + countRow][countColumn].tm_mon == monthToShow) // phan tu trong thang
            {
                Pos[ztemp].day = data[iStart + countRow][countColumn].tm_mday;
                ztemp++;
            }
            else
                break;
        }
        if (data[iStart + countRow][countColumn].tm_mon == monthToShow)
            countRow++;
        else
            break;
    }

    //Xuat lich theo ngany

    for (i; i <= row; i++)
    {

        for (j = 1; j <= column; j++)
        {
            Pos[ele].xP = Pos[0].xP + disx * j;
            Pos[ele].yP = coorY;
            //Pos[ele].state = 0;

            //neu in lich theo thang, nam thi ko can doan nay
            //*
            if (i == 1)
            {
                switch (j)
                {
                case 1:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Mo");
                    changeColor(07);
                    break;
                }
                case 2:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Tu");
                    changeColor(07);
                    break;
                }
                case 3:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("We");
                    changeColor(07);
                    break;
                }
                case 4:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Th");
                    changeColor(07);
                    break;
                }
                case 5:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Fr");
                    changeColor(07);
                    break;
                }
                case 6:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Sa");
                    changeColor(07);
                    break;
                }
                case 7:
                {
                    SetCursorPosition(Pos[ele].xP, Pos[ele].yP - 2);
                    changeColor(02);
                    printf("Su");
                    changeColor(07);
                    break;
                }
                }
            }
            //*/

            if (i == 1 && j < invalidEle)
            {
                SetCursorPosition(Pos[ele].xP, Pos[ele].yP);
                printf("  ");
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP - 1);
                deleteBoard1();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP);
                deleteBoard2();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP + 1);
                deleteBoard1();
            }
            else
            {
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP - 1);
                createBoard1();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP);
                createBoard2();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP + 1);
                createBoard3();
                SetCursorPosition(Pos[ele].xP, Pos[ele].yP);
                printf("%2d", Pos[ele].day); //sua o
            }
            ele++;
            if (ele == total)
                break;
        }
        if (ele == total)
            break;
        coorY += disy;
    }

    if (DateOfGTD > 100)
        {
            int temp = invalidEle;
            for (temp; temp<=total;temp++)
                if (Pos[temp].day == (DateOfGTD - 100))
                    {
                        firstEle = temp;
                        break;
                    }
            DateOfGTD = 0;
        }

    if (flag == 0)
    {
        int i = 1;
        for (i; i < total; i++)
            if (Pos[i].day == thisD)
                firstEle = i;
        flag = 1;
    }

    int iCN=0, jCN;
    for(iCN;iCN<5;iCN++)
    {
        gotoxy(20, 25+iCN);
        printf("                                  ");
    }
    char tempCN[50];
    iCN = 0;
    for (jCN=1;jCN<=n;jCN++)
    {
        strcpy(tempCN,"");
        strcpy(checkNote, "");
        strcpy(userFileNote, "");
        //strcpy(userFileNote, username);
        sprintf(userFileNote, "%s-%d-%d-%d", username, jCN, dataforPreMonth[*count].month, dataforPreMonth[*count].year);
        //strcat(userFileNote, checkNote);
        FILE *fpcheck = fopen(userFileNote, "r");
        gotoxy(20, 25+iCN);
        if (fpcheck)
        {
            strcpy(tempCN,"");
            iCN+=1;
            strcpy(checkNote, "");
            fgets(checkNote,25,fpcheck);
            sprintf(tempCN,"%d-%d-%d: %s...",jCN, dataforPreMonth[*count].month, dataforPreMonth[*count].year,checkNote);
            
            printf("%s",tempCN);
            
            //printf("%s", tempCN);
            fclose(fpcheck);
        }
        if (iCN>0)
            {
                gotoxy(20,23+6);
                printf("See full note in EVENT menu");
            }
        if (iCN==5)
            break;
    }
    // Change color

    int hlColor = 112;  // mau ngay duoc chon
    int specColor = 7; // mau ngay dac biet

    if (monthToShow == thisM && dataforPreMonth[*count].year == thisY){
        specColor = 2;
    }

    //hightlighted days:
    int o = 0;
    int day = 1;
    int hlDay[1];
    hlDay[0]=thisD;

    for (o; o < day; o++)
    {
        changeColor(specColor);
        SetCursorPosition(Pos[hlDay[o] + invalidEle - 1].xP, Pos[hlDay[o] + invalidEle - 1].yP);
        printf("%2d", Pos[hlDay[o] + invalidEle - 1].day);
        changeColor(7);
    }

    //first element
    changeColor(hlColor);
    SetCursorPosition(Pos[firstEle].xP, Pos[firstEle].yP);
    printf("%2d", Pos[firstEle].day);
    changeColor(7);
    SetCursorPosition(0, 4);

    if (stateFlag == 0)
    {
        gotoxy(4,31);
        printf("*Enter to Year");
        //handle arrow key
        int preEle = firstEle;
        int newEle;
        int ch;
        while ((ch = _getch())) //27 = Esc key
        {

            if (ch == 27)
            {
                state = stateOfMenu;
                saveState = 0;
                break;
            }
            if (ch == 8)
            {
                state = 1;
                //*countMonth = *count/12;
                startingMonth = monthToShow;
                //getch();
                break;
            }
            else
            {
                if (ch == 0 || ch == 224)
                {
                    ch = _getch();
                    newEle = handleArrowKey(row, column, total, preEle, ch, invalidEle, count);
                    if (saveCount != *count)
                    {
                        //*count = saveCount;
                        break;
                    }
                    else
                    {
                        //clear previous
                        if (newEle != preEle && newEle >= invalidEle)
                        {
                            changeColor(7);
                            SetCursorPosition(Pos[preEle].xP, Pos[preEle].yP);
                            printf("%2d", Pos[preEle].day);
                            SetCursorPosition(0, 10);
                            //printf("PreE %d NewE %d Total %d", preEle, newEle, total);
                        }

                        //recolor special days
                        for (o = 0; o < day; o++)
                        {
                            if (preEle == hlDay[o] + invalidEle - 1)
                            {
                                changeColor(specColor);
                                SetCursorPosition(Pos[hlDay[o] + invalidEle - 1].xP, Pos[hlDay[o] + invalidEle - 1].yP);
                                printf("%2d", Pos[hlDay[o] + invalidEle - 1].day);
                                changeColor(7);
                            }
                        }

                        preEle = newEle;

                        //color current
                        if (newEle >= invalidEle)
                        {
                            changeColor(hlColor);
                            SetCursorPosition(Pos[newEle].xP, Pos[newEle].yP);
                            printf("%2d", Pos[newEle].day);
                            changeColor(7);
                            SetCursorPosition(0, 5);
                        }
                    }
                }
            }
        }
        //system("cls");
        startingDay = ((newEle <= 7 + invalidEle) ? ((newEle + 35 > 38) ? newEle + 28 : newEle + 35) : ((newEle - 35 < 0) ? newEle - 28 : newEle - 35));
        ele = 28;
        for (i = 3; i <= row; i++)
        {

            for (j = 1; j <= column; j++)
            {
                SetCursorPosition(Pos[ele].xP, Pos[ele].yP);
                printf("  ");
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP - 1);
                deleteBoard1();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP);
                deleteBoard2();
                SetCursorPosition(Pos[ele].xP - 2, Pos[ele].yP + 1);
                deleteBoard1();
                ele++;
                if (ele == total)
                    break;
            }
            if (ele == total)
                break;
            coorY += disy;
        }
    }
}

void SetCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(output, pos);
}

int handleArrowKey(int row, int column, int total, int preEle, int ch, int invalidEle, int *count)
{

    int newEle;
    switch (ch)
    {
    case 72:
    {
        if (preEle > (column))
        {
            newEle = preEle - column; //DI LEN
            if (newEle < invalidEle)
                *count -= 1;
        }
        else
            *count -= 1;
        ;

        break;
    }
    case 75:
    {
        if (preEle > 1)
        {
            newEle = preEle - 1; //SANG TRAI
        }
        else
            newEle = preEle;
        break;
    }
    case 80:
    {
        if (preEle <= (total - 1 - column))
            newEle = (((preEle + column) > total) ? total : (preEle + column)); //DI XUONG
        else
        {
            *count += 1;
        }
        break;
    }
    case 77:
    {
        if (preEle != total)
            newEle = preEle + 1; //SANG PHAI
        else
            newEle = preEle;
        break;
    }
    }
    SetCursorPosition(0, 5);
    //printf("%d",*count);
    if (newEle >= invalidEle && newEle < total)
        return newEle;
    else
        return preEle;
}

void formatConsole(int *xp0, int *yp0, int *disx, int *disy)
{
    int xp, yp, disX, disY;
    printf("Le ngang, le doc, khoang cach dong, khoang cach cot:\n ");
    scanf("%d%d%d%d", &xp, &yp, &disX, &disY);
    *xp0 = xp;
    *yp0 = yp;
    *disx = disX;
    *disy = disY;
}

void getNumberOfElements(int *n)
{
    int num;
    printf("Input number of elements: ");
    scanf("%d", &num);
    *n = num;
    system("cls");
}

void getFirstHighlightedEle(int n, int *firstEle)
{
    int temp;
    do
    {
        printf("Input the first highlighted element: ");
        scanf("%d", &temp);
    } while (temp < 0 || temp > n);
    *firstEle = temp;
}

void getColumn(int *col, int n)
{
    int temp;
    do
    {
        printf("Column: ");
        scanf("%d", &temp);
    } while (temp > n);
    *col = temp;
}

int *getSpecialDays(int invalidEle, int n, int specColo, int *day)
{
    int o;
    SetCursorPosition(0, 28);
    printf("Input day(s) you want to highlight: ");
    scanf("%d", day);
    printf("number of days: %d", *day);
    fflush(stdin);

    int *hlDays;
    hlDays = (int *)malloc(*day * sizeof(int));
    SetCursorPosition(0, 30);
    for (o = 0; o < *day; o++)
    {
        do
        {
            scanf("%d", &hlDays[o]);
            fflush(stdin);
        } while (hlDays[o] <= 0 || hlDays[o] > n);
    }
    o = 0;
    while (o < *day)
    {
        printf("?%d", hlDays[o]);
        o++;
    }
    return hlDays;
}

void createBoard1()
{
    printf("%c%c%c%c%c%c", chA, chE, chE, chE, chE, chB);
}

void createBoard2()
{
    printf("%c    %c", chF, chF);
}

void createBoard3()
{
    printf("%c%c%c%c%c%c", chC, chE, chE, chE, chE, chD);
}

void deleteBoard1()
{
    printf("      ");
}

void deleteBoard2()
{
    printf("      ");
}

void deleteBoard3()
{
    printf("      ");
}

void createBoard4()
{
    printf("%c%c%c%c%c%c%c%c%c%c", chA, chE, chE, chE, chE, chE, chE, chE, chE, chB);
}

void createBoard5()
{
    printf("%c        %c", chF, chF);
}

void createBoard6()
{
    printf("%c%c%c%c%c%c%c%c%c%c", chC, chE, chE, chE, chE, chE, chE, chE, chE, chD);
}

int isLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0);
}

int month(int a, int b)
{
    int i = 0;
    int arr[13] = {0, 31, 28 + isLeapYear(b), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (i = 1; i < 14; i++)
        if (i == a)
            return arr[i];
}
void createData()
{
    int checkMonth, year;

    data[0][0].tm_mday = 1;
    checkMonth = 1;
    year = 1;

    int i, j;
    for (i = 0; i < 106000; i++)
    {
        for (j = 0; j < 7; j++)
        {
            data[i][j + 1].tm_mday = data[i][j].tm_mday + 1;
            data[i + 1][0].tm_mday = data[i][6].tm_mday + 1;

            data[i][j].tm_mon = checkMonth;
            data[i][j].tm_year = year;

            if (data[i][j].tm_mday == month(checkMonth, year))
            {
                {
                    if (j != 6)
                        data[i][j + 1].tm_mday = 1;
                    else
                        data[i + 1][0].tm_mday = 1;
                    checkMonth++;
                }

                if (checkMonth == 13)
                {
                    year++;
                    checkMonth = 1;
                }
            }
        }
    }
}

void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

char createFrame(int xFrame, int yFrame, int aFrame, int bFrame, int color)
{

    int saveX, saveY;

    saveX = xFrame;
    saveY = yFrame;

    changeColor(color);

    //ve dong ngang tren va duoi
    for (xFrame; xFrame < aFrame + saveX + 1; xFrame++)
    {
        gotoxy(xFrame, yFrame);
        printf("%c", chE);
        gotoxy(xFrame, bFrame + yFrame);
        printf("%c", chE);
    }

    //ve dong doc phai va trai
    xFrame = saveX;
    for (yFrame; yFrame < bFrame + saveY + 1; yFrame++)
    {
        gotoxy(xFrame, yFrame);
        printf("%c", chF);
        gotoxy(aFrame + xFrame, yFrame);
        printf("%c", chF);
    }

    //ve cac goc vuong
    yFrame = saveY;
    gotoxy(xFrame, yFrame);
    printf("%c", chA);
    gotoxy(aFrame + xFrame, yFrame);
    printf("%c", chB);
    gotoxy(xFrame, bFrame + yFrame);
    printf("%c", chC);
    gotoxy(aFrame + xFrame, bFrame + yFrame);
    printf("%c", chD);

    changeColor(07);
}

char UIFrameMain(int color)
{

    createFrame(1, 1, 16, 29, color);
    createFrame(18, 1, 43, 22, color);
    createFrame(18, 23, 43, 7, color);
}

char UIFrameEventOfDate(int color)
{

    int i;
    createFrame(1, 1, 16, 29, color);
    createFrame(18, 1, 43, 22, color);
    for (i = 18; i < 43 + 18; ++i)
    {
        changeColor(00);
        gotoxy(i, 23);
        printf("%c", chE);
        changeColor(07);
    }
    createFrame(18, 8, 43, 22, color);
}

char UIFrameAddEvent(int color)
{

    createFrame(1, 1, 16, 29, color);
    createFrame(18, 1, 43, 29, color);
    //	createFrame(18, 23, 43, 7, color);
}

void changColorOfUI()
{
}

char UIMenu1(int colorLogin, int colorRegister, int colorGuest)
{

    //chu MENU
    changeColor(04);
    gotoxy(4, 3);
    printf("%c%c%c%c%c%c%c%c%c %c", chG, chE, chB, chG, chE, chG, chE, chB, chG, chA);
    gotoxy(4, 4);
    printf("%c%c%c%c%c%c %c%c %c", chH, chF, chF, chH, chE, chH, chF, chH, chF);
    gotoxy(4, 5);
    printf("%c%c%c%c%c%c %c%c%c%c", chI, chC, chC, chI, chE, chI, chC, chI, chE, chD);
    changeColor(07);

    createFrame(3, 8, 12, 2, colorLogin);
    gotoxy(7, 9);
    changeColor(colorLogin);
    printf("Login");
    changeColor(07);
    createFrame(3, 11, 12, 2, colorRegister);
    gotoxy(6, 12);
    changeColor(colorRegister);
    printf("Register");
    changeColor(07);
    createFrame(3, 14, 12, 2, colorGuest);
    gotoxy(7, 15);
    changeColor(colorGuest);
    printf("Guest");
    changeColor(07);
    createFrame(3, 17, 12, 2, 07);
    gotoxy(7, 18);
    printf("Exit");
}

char UILogin(int color)
{

    int colorLogin;
    UIFrameMain(color);
    colorLogin = color;
    UIMenu1(colorLogin, 07, 07);

    //chu LOGIN
    changeColor(04);
    gotoxy(34, 4);
    printf("%c %c%c%c%c%c %c%c%c%c", chJ, chG, chE, chB, chG, chE, chJ, chG, chE, chB);
    gotoxy(34, 5);
    printf("%c %c %c%c %c%c%c %c", chH, chH, chF, chH, chB, chH, chH, chF);
    gotoxy(34, 6);
    printf("%c%c%c%c%c%c%c%c%c%c %c", chI, chE, chI, chE, chD, chI, chE, chD, chI, chI, chC);
    changeColor(07);

    gotoxy(36, 9);
    printf("User name");
    createFrame(25, 10, 29, 2, 07);
    gotoxy(36, 13);
    printf("Password");
    createFrame(25, 14, 29, 2, 07);
    createFrame(34, 18, 12, 2, 04);
    gotoxy(38, 19);
    printf("Login");
}

char UIRegister(int color)
{

    int colorRegister;
    UIFrameMain(color);
    colorRegister = color;
    UIMenu1(07, colorRegister, 07);

    //chu REGISTER
    changeColor(04);
    gotoxy(30, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", chG, chE, chB, chG, chE, chG, chE, chB, chJ, chG, chE, chB, chE, chJ, chE, chG, chE, chG, chE, chB);
    gotoxy(30, 5);
    printf("%c  %c%c%c %c%c%c%c%c %c %c%c%c", chH, chH, chE, chH, chB, chH, chI, chE, chB, chH, chH, chE, chH);
    gotoxy(30, 6);
    printf("%c  %c%c%c%c%c%c%c%c%c %c %c%c%c", chI, chI, chE, chI, chE, chD, chI, chI, chE, chD, chI, chI, chE, chI);
    changeColor(07);

    gotoxy(36, 9);
    printf("User name");
    createFrame(25, 10, 29, 2, 07);
    gotoxy(36, 13);
    printf("Password");
    createFrame(25, 14, 29, 2, 07);
    createFrame(34, 18, 12, 2, 04);
    gotoxy(37, 19);
    printf("Sign up");

}

char UIGuest(int color)
{

    int colorGuest;
    UIFrameMain(color);
    colorGuest = color;
    UIMenu1(07, 07, colorGuest);

    changeColor(color);
    gotoxy(23, 25);
    printf("Please login to use the function!");
    changeColor(07);
}

char UIMenu2(int colorMonth, int colorYear, int colorDecade, int colorEvent, int colorGoToDate, int colorSetting)
{

    //chu MENU
    changeColor(04);
    gotoxy(4, 3);
    printf("%c%c%c%c%c%c%c%c%c %c", chG, chE, chB, chG, chE, chG, chE, chB, chG, chA);
    gotoxy(4, 4);
    printf("%c%c%c%c%c%c %c%c %c", chH, chF, chF, chH, chE, chH, chF, chH, chF);
    gotoxy(4, 5);
    printf("%c%c%c%c%c%c %c%c%c%c", chI, chC, chC, chI, chE, chI, chC, chI, chE, chD);
    changeColor(07);

    createFrame(2, 8, 14, 2, colorMonth);
    gotoxy(7, 9);
    changeColor(colorMonth);
    printf("Month");
    changeColor(07);
    createFrame(2, 11, 14, 2, colorYear);
    gotoxy(7, 12);
    changeColor(colorYear);
    printf("Year");
    changeColor(07);
    createFrame(2, 14, 14, 2, colorDecade);
    gotoxy(7, 15);
    changeColor(colorDecade);
    printf("Decade");
    changeColor(07);
    createFrame(2, 17, 14, 2, colorEvent);
    gotoxy(7, 18);
    changeColor(colorEvent);
    printf("Event");
    changeColor(07);
    createFrame(2, 20, 14, 2, colorGoToDate);
    gotoxy(5, 21);
    changeColor(colorGoToDate);
    printf("Go to date");
    changeColor(07);
    createFrame(2, 23, 14, 2, colorSetting);
    gotoxy(6, 24);
    changeColor(colorSetting);
    printf("Setting");
    changeColor(07);
}

char UIMonth(int color)
{

    int colorMonth;
    UIFrameMain(color);
    colorMonth = color;
    UIMenu2(colorMonth, 07, 07, 07, 07, 07);

    changeColor(04);
    gotoxy(20, 24);
    printf("Event of date: ");
    changeColor(07);
}

char UIYear(int color)
{

    int colorYear;
    UIFrameMain(color);
    colorYear = color;
    UIMenu2(07, colorYear, 07, 07, 07, 07);
}

char UIDecade(int color)
{

    int colorDecade;
    UIFrameMain(color);
    colorDecade = color;
    UIMenu2(07, 07, colorDecade, 07, 07, 07);
}

char UIEventOfDate(int color)
{

    int colorMonth;
    UIFrameEventOfDate(color);
    colorMonth = color;
    UIMenu2(colorMonth, 07, 07, 07, 07, 07);

    changeColor(04);
    gotoxy(20, 9);
    printf("Event of date: ");
    changeColor(07);
    createFrame(20, 10, 39, 4, 07);
    createFrame(20, 15, 39, 4, 07);
    createFrame(20, 20, 39, 4, 07);
    createFrame(20, 25, 39, 4, 07);
}

char UIAddEvent(int color)
{

    int colorEvent;
    UIFrameAddEvent(color);
    colorEvent = color;
    UIMenu2(07, 07, 07, colorEvent, 07, 07);

    changeColor(04);
    gotoxy(21, 3);
    printf("EVENT MENU");
    changeColor(07);

    createFrame(20, 8, 39, 18, 07);
}

char UIGoToDate(int color)
{

    int colorGoToDate;
    UIFrameMain(color);
    colorGoToDate = color;
    UIMenu2(07, 07, 07, 07, colorGoToDate, 07);

    changeColor(04);
    gotoxy(35, 23);
    printf("GO TO DATE");
    changeColor(07);
}

char UISetting(int color)
{

    int colorSetting;
    UIFrameMain(color);
    colorSetting = color;
    UIMenu2(07, 07, 07, 07, 07, colorSetting);

    //chu SETTING
    changeColor(04);
	gotoxy(30, 3); printf("%c%c%c%c%c %c%c%c%c%c%c %c%c%c%c%c%c%c", chG, chE, chB, chG, chE, chE, chJ, chE, chE, chJ, chE, chJ, chG, chE, chB, chG, chE, chB);
	gotoxy(30, 4); printf("%c%c%c%c%c  %c  %c  %c%c %c%c %c", chI, chE, chB, chH, chE, chH, chH, chH, chH, chF, chH, chB);
	gotoxy(30, 5); printf("%c%c%c%c%c  %c  %c  %c%c %c%c%c%c", chC, chE, chD, chI, chE, chI, chI, chI, chI, chC, chI, chE, chD);
	changeColor(07);
}

void dayNow(int *thisDay, int *thisMonth, int *thisYear)
{
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = gmtime(&rawtime);
    //printf("%d/%02d/%d", info -> tm_mday, info -> tm_mon + 1, 1900 + info -> tm_year);
    *thisDay = info->tm_mday;
    *thisMonth = info->tm_mon + 1;
    *thisYear = 1900 + info->tm_year;
    //printf("\n%d\n", *thisYear);
}

void dayNowShow()
{
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = gmtime(&rawtime);
    SetCursorPosition(2, 0);
    changeColor(2);
    printf("Today: %d/%02d/%d", info->tm_mday, info->tm_mon + 1, 1900 + info->tm_year);
    changeColor(7);
}

//==============================================================
//==============================================================

int takeDay()
{
    int day;
    printf("Day: ");
    scanf("%d", &day);
    return day;
}
int takeMonth()
{
    int month;
    printf("Month: ");
    scanf("%d", &month);
    return month;
}
int takeYear()
{
    int year;
    printf("Year: ");
    scanf("%d", &year);
    return year;
}
int valid(int d, int m, int y)
{
    if (y < 1980 || y > 2032)
        return 0;
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12)
        return 0;

    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxd = 30;
    else if (m == 2)
    {

        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            maxd = 29;
        else
            maxd = 28;
    }
    return d <= maxd;
}

void createAndFixNote(char *fileName)
{
    char c;
    int marg = 23;
    int len = 30;
    int curRow = 10;
    int limitRowAbove = 10;
    int limitRowBelow = limitRowAbove + 14;
    SetCursorPosition(40, limitRowAbove - 1);
    printf("%s:", fileName);
    SetCursorPosition(20, limitRowBelow + 4);
    changeColor(3);
    printf("Press 'TAB' to finish your note !");
    changeColor(7);
    SetCursorPosition(marg, curRow);
    FILE *fp = fopen(userFileNote, "w");
    if (!fp)
        {
            gotoxy(0,0);
            printf("Canttttt");
            getch();
        }
    int i = 1;
    int inflag = 0;
    fflush(stdin);
    while ((c = _getch()) != 9)
    {

        if (curRow > limitRowBelow || curRow < limitRowAbove && inflag == 1)
        {
            curRow = ((curRow > limitRowBelow) ? (limitRowBelow - 1) : (limitRowAbove + 1));
            printf("stop");
        }

        if (c == 13)
        {
            if (curRow >= limitRowBelow)
                curRow -= 1;
            curRow += 1;
            SetCursorPosition(marg, curRow);
            fprintf(fp, "%c",200);
            i = 1;
        }
        else if (c == 8 && flag == 1)
        {
            if (i == 0 && curRow != limitRowAbove)
            {
                curRow -= 1;
                //SetCursorPosition(marg,curRow);
                //printf(" ");
                SetCursorPosition(marg + len + 1, curRow);
                printf("\b\b   \b\b\b");
                fseek(fp, -1, SEEK_CUR);
                fprintf(fp, " ");
                fseek(fp, -1, SEEK_CUR);

                i = len - 1;
            }
            else if (i > 0)
            {
                printf("\b \b");
                fseek(fp, -1, SEEK_CUR);
                fprintf(fp, " ");
                fseek(fp, -1, SEEK_CUR);
                i -= 1;
            }
        }
        else
        {
            printf("%c", c);
            fprintf(fp, "%c", c);
            i += 1;
        }

        if (i == len)
        {
            if (curRow >= limitRowBelow)
            {
                //i=1;
                curRow = limitRowBelow - 1;
                SetCursorPosition(marg + len, curRow);
                while (c = _getch() != 8)
                {
                    SetCursorPosition(marg + 20, curRow + 9);
                    changeColor(64);
                    printf("Not enough space");
                    changeColor(7);
                }
                SetCursorPosition(marg + 20, curRow + 9);
                printf("                ");
                SetCursorPosition(marg + len, curRow + 1);
                continue;
            }
            if (toupper(c) >= 'A' && toupper(c) <= 'Z')
            {
                printf("-");
                curRow += 1;
                SetCursorPosition(marg, curRow);
                printf("-");
                fprintf(fp, "-%c-",200);
                i = 2;
            }
            else
            {
                curRow += 1;
                SetCursorPosition(marg, curRow);

                fprintf(fp, "%c",200);
                i = 1;
            }
        }
        inflag = 1;
    }
    fclose(fp);
    SetCursorPosition(marg + 13, 25);
    changeColor(47);
    printf("Complete!");
    free(fileName);
    changeColor(7);

    SetCursorPosition(20, limitRowBelow + 4);
    changeColor(3);
    printf("Type 'a' to add more note !             ");
    SetCursorPosition(20, limitRowBelow + 5);
    printf("Use other keys to return to note menu...");
    changeColor(7);
    fflush(stdin);
    c = _getch();
    fflush(stdin);
    if (c == 'a')
    {
        addNoteFlag = 1; //tiep tuc add note
    }
    else 
    {
        addNoteFlag = 0; //ra ngoai menu
    }
}
void readNote(char *fileName)
{
    SetCursorPosition(20, 24 + 4);
    changeColor(3);
    printf("Type 'r' to read more note !             ");
    SetCursorPosition(20, 24 + 5);
    printf("Use other keys to return to note menu...");
    changeColor(7);
    char c;

    int i =1;
    int marg = 23;
    int len = 30;
    int curRow = 10;
    int limitRowAbove = 10;
    int limitRowBelow = limitRowAbove + 14;
    SetCursorPosition(40, limitRowAbove - 1);
    printf("%s:", fileName);
    SetCursorPosition(20, limitRowBelow + 4);
    changeColor(7);
    char *buff = (char *)malloc(500 * sizeof(char));
    FILE *fpr = fopen(userFileNote, "r");
    //fseek(fpr,-100,SEEK_CUR);
    if (!fpr)
    {
        changeColor(64);
        SetCursorPosition(24, 17);
        printf("Can't find note");
        changeColor(7);
	}
    char ch;
    char check = 200;
    SetCursorPosition(marg, curRow);
    while ((ch = fgetc(fpr)) != EOF)
    {
        if (ch == check)
        {
            curRow+=1;
            SetCursorPosition(marg, curRow);
            //curRow+=1;
        }
        else
            printf("%c", ch);
    }
    fflush(stdin);
    c = _getch();
    fflush(stdin);
    if (c == 'r')
    {
        readNoteFlag = 1; //tiep tuc add note
    }
    else 
    {
        readNoteFlag = 0; //ra ngoai menu
    }
    fclose(fpr);
    free(fileName);
    

}
void removeNote(char *fileName)
{
    SetCursorPosition(20, 24 + 4);
    changeColor(3);
    printf("Type 'x' to remove more note !             ");
    SetCursorPosition(20, 24 + 5);
    printf("Use other keys to return to note menu...");
    char c;
    remove(userFileNote);
    SetCursorPosition(24, 17);
    printf("%s has been removed", fileName);
    fflush(stdin);
    c = getch();
    fflush(stdin);
    if (c == 'x')
    {
        removeNoteFlag = 1; //tiep tuc add note
    }
    else 
    {
        removeNoteFlag = 0; //ra ngoai menu
    }
    free(fileName);
}
char *takeFileName()
{

    int day, month, year;
    int temp;
    SetCursorPosition(21, 6);
    printf("                               ");
    do
    {
        if (temp == 1)
        {
            SetCursorPosition(21, 5);
            changeColor(64);
            printf("Enter again");
            changeColor(7);
            //SetCursorPosition(21, 5);
            //gotoxy(21, 6);
            //printf("                         ");
            //SetCursorPosition(29, 5);
            //printf("             ");
            
        }

        SetCursorPosition(21, 6);
        day = takeDay();
        fflush(stdin);
        SetCursorPosition(29, 6);
        month = takeMonth();
        fflush(stdin);
        SetCursorPosition(40, 6);
        year = takeYear();
        fflush(stdin);

        temp = 1;
    } while (!valid(day, month, year));

    SetCursorPosition(21, 5);
    printf("             ");
    char *strp = (char *)malloc(20 * sizeof(char));
    if (!strp)
        printf("error");
    else
    {
        sprintf(strp, "Note of %d %d %d", day, month, year);
        strcpy(userFileNote,"");
        //strcpy(userFileNote,username);
        sprintf(userFileNote,"%s-%d-%d-%d",username,day,month,year);
        fflush(stdin);
        return strp;
    }
}
////////////////////////////////////


int event(int a)
{
	int arr[13] = {0,2,5,6,8,10,12,12,13,13,14,16,18};
	int t1, t2;
    FILE *fp;
    char buff[50];
    fp = fopen("dataEvent2.txt", "a+");
    int i;
	for ( i = 1; i < 14; i++)
	{
		if (i == a)
			{
				t1 = arr[i - 1];
				t2 = arr[i] - arr[i-1];
			}
	}
	here:
	if(t1!=0)
	{
        //fscanf(fp,"%s",buff);
        //fscanf(fp,"%s",buff);
        fgets(buff, 60, (FILE*)fp);
        t1--;
        goto here;
	}
	else
	{
		here1:
    	if(t2 !=0 )
    	{
    		//fscanf(fp,"%s",buff);
        	//fscanf(fp,"%s",buff);
        	fgets(buff, 60, (FILE*)fp);
        	printf("%s",buff);
    		t2--;
    		goto here1;
   		}
	}
}

/////////////////////////////////////////
//REGISTER

int checkUserR(int a, int b)
{
	return (((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >='a' && a <= 'z')) && b < 20);
}

int checkUserNameR(char s[20])
{
    FILE *fp;
    char buff[20];
    fp = fopen("dataUser.txt", "r");
    here:
        fscanf(fp, "%s", buff);
    if(strcmp(s, buff) == 0)
    {
        gotoxy(22,27);
        printf("                                    ");
        gotoxy(22,27);
        printf("Sorry, your username has been taken!");
        gotoxy(22,28);
        printf("                                    ");
        gotoxy(22,28);
        printf("Please try again...");
        gotoxy(27+pos,11);
        return 0;
    }
    else
    {
        if(fgets(buff,2,(FILE*)fp) != NULL)
        	goto here;
        else
        	return 1;
    }
}

int createUserNameR()
{
    pos = 0;
    gotoxy(32,17);
    printf("                            " );
    gotoxy(27,22);
    printf(" Press esc to get back to menu");
    gotoxy(27,21);
    printf(" Press 'enter' to continue");
	char s[20];
	int n, slen=0;
    gotoxy(27,11);
	printf("                      ");
    gotoxy(27,15);
    printf("                      ");
    gotoxy(27,11);
	here:
	do
    {
        fflush(stdin);
        n = getch();
        if (n == 27)
            goto end;
        if (checkUserR(n,slen) == 1)
		{
            s[slen++] = n;
            printf( "%c",n);
            pos+=1;
        }
        if (n == '\b' && slen > 0)
		{
            s[--slen] = 0;
            printf ("\b \b");
            pos = (pos==0 ? 0 : pos-1);
        }
        if(slen < 4)
        	goto here;
    }
    while (n!=13);

    if (slen == 0)
    	goto here;
    if(checkUserNameR(s) == 0)
    	goto here;
    else
    	{
    		int i;
    		FILE *fp;
			fp = fopen ("dataUser.txt","a+");
            //strcpy(username,"");
			for ( i=0;i<slen;i++)
        	{
                fprintf(fp,"%c",s[i]);
                
            }
			fprintf(fp," ");
			fclose(fp);
            return 0;
            end: return 100;
		}
}

int createPassWordR()
{
    char s[20];
    int n, slen=0;
    gotoxy(27,15);
    here:
    do
    {
        n = getch();
        if (n == 27)
            goto end;
        if (checkUserR(n,slen) == 1)
		{
            s[slen++] = n;
            printf("*",n);
        }
        if (n == '\b' && slen > 0)
		{
            s[--slen] = 0;
            printf ("\b \b");
        }
        if(slen<4)
        	goto here;
    }
    while (n!=13);
    if (slen == 0)
    	goto here;
    	
	FILE *fp;
	fp = fopen ("dataUser.txt","a+");
	int i;
	for ( i=0;i<slen;i++)
        fprintf(fp,"%c",s[i]);
	fprintf(fp,"* \n");
	fclose(fp);
    return 0;
    end: return 100;
}
int createNameR()
{
	char s[200];
	int n,slen;
    gotoxy(32,17);
	printf("   Name: ");
	gets(s);
	FILE *fp;
	fp=fopen("dataName.txt","a+");
	fprintf(fp,"%s\n",s);
	fclose(fp);
}
int registerUserR()
{
    if (createUserNameR() == 100 )
        goto end;
    createPassWordR();
	createNameR();
    FILE *fp;
    fp = fopen("data.txt","a+");
    fprintf(fp," \n");
    fclose(fp);
    end:
        return 0;
}

//LOGIN

int checkUser(int a, int b)
{
	return (((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >='a' && a <= 'z')) && b < 20);
}
int createUserName()
{
    gotoxy(27,22);
    printf(" Press esc to get back to menu");
    gotoxy(27,21);
    printf(" Press 'enter' to continue");
    gotoxy(27,11);
	printf("                      ");
    gotoxy(27,15);
    printf("                      ");
    gotoxy(27,11);
	char s[20];
	int n, slen=0;
    
	here:
	do
    {
        n = getch();
        if (n == 27)
            goto end;
        if (checkUser(n,slen) == 1)
		{
            s[slen++] = n;
            printf( "%c",n);
        }
        if (n == '\b' && slen > 0)
		{
            s[--slen] = 0;
            printf ("\b \b");
        }
    }
    while (n!=13);
    if (slen == 0)
    	goto here;
    char s2[20];
    int n2, slen2=0;
    gotoxy(27,15);
    here2:
    do
    {
        n2 = getch();
        if (n2 == 27)
            goto end;
        if (checkUser(n2,slen2) == 1)
		{
            s2[slen2++] = n2;
            printf("*",n2);
        }
        if (n2 == '\b' && slen2 > 0)
		{
            s2[--slen2] = 0;
            printf ("\b \b");
        }
    }
    while (n2!=13);
    if (slen2 == 0)
    	goto here2;
	s2[slen2++]='*';
    strcat(s,s2);
    checkUserName(s);
    end:
        return 0;
}
int name(int a)
{
	FILE *fp;
	fp=fopen("dataName.txt","a+");
	char buff2[200];
	here:
		fgets(buff2, 200,(FILE*)fp);
		a--;
	if(a!=0)
		goto here;
	else
		printf("%s",buff2);	
}
int checkUserName(char s[65])
{
    FILE *fp;
    fp = fopen("dataUser.txt", "r");
    
    if (!fp)
        {
            printf("error");
            getch();
        }
    char buff[65];
    char s1[65], s2[65]="";
    int t=0;
    here:
        strcpy(username, "");
        strcpy(s1,s2);
        fscanf(fp, "%s", buff);
    	strcat(s1,buff);
        strcpy(username, buff);
        fscanf(fp, "%s", buff);
		strcat(s1,buff);
		t++;
    if(strcmp(s, s1) == 0)
    {
        
        //strcpy(username, s);
        gotoxy(27,27);
        printf("                               ");
        gotoxy(27,27);
        printf("        Welcome ");
        name(t);
        gotoxy(27,22);
        printf("                              ");
        gotoxy(27, 21);
        printf("                               ");
        gotoxy(22, 21);
        printf("Please press any keys to continue!");
        gotoxy(0,0);
        //int temp=0;
        //strcpy(username,username+temp);
        //printf("%s", username);
        loginFlag = 1;
        fflush(stdin);
        getch();
        fflush(stdin);
        return 0;
    }
    else
    {
        if(fgets(buff,2,(FILE*)fp) != NULL)
        	goto here;
        else
        {
            gotoxy(27,27);
        	printf("Wrong username or password      ");
            getch();
        }
    }
    fclose(fp);
}
