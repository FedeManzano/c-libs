#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./date.h"

int comp_date(const void *f1, const void *f2 ){

    if(!f1 || !f2)
        return DATE_ERROR;


    t_date * fe1 = (t_date *)f1;
    t_date * fe2 = (t_date *)f2;


    if(val_date(fe1->d,fe1->m,fe1->y) == DATE_ERROR)
        return DATE_ERROR;
    if(val_date(fe2->d,fe2->m,fe2->y) == DATE_ERROR)
        return DATE_ERROR;

    if(fe1->y == fe2->y && fe1->m == fe2->m && fe1->d == fe2->d)
        return 0;

    if(fe1->y == fe2->y){
        if(fe1->m == fe2->m){
            return fe1->d > fe2->d ? 1: fe1->d < fe2->d ? -1:0;
        } else{
            return fe1->m > fe2->m ? 1: fe1->m < fe2->m ? -1:0;
        }
    }

    return fe1->y > fe2->y ? 1:fe1->y < fe2->y ? -1:0;
}

int comp_time(const void *d1, const void *d2){
    t_date *date1 = (t_date *) d1;
    t_date *date2 = (t_date *) d2;
    int compDate = comp_date(d1,d2);
    if(!compDate){
        if(date1->hh != date2->hh)
            return date1->hh > date2->hh ? 1 : -1;
        if(date1->mm != date2->mm)
            return date1->mm > date2->mm ? 1 : -1;
        if(date1->ss != date2->ss)
            return date1->ss > date2->ss ? 1 : -1;
        return 0;
    }
    return compDate == 1 || compDate == -1 ? compDate:DATE_ERROR;
}

int val_date(const int day, const int month, const int year){
    int vday = days_of_month(year,month);
    if(vday == DATE_ERROR)
        return DATE_ERROR;
    return day < 1 || day > vday ? DATE_ERROR: OK;
}

int val_time(const int day,const int month, const int year, const int hour, const int minute, const int second){
    if(val_date(day,month,year) == DATE_ERROR)
        return DATE_ERROR;
    if(hour < 0 || hour > 23)
        return DATE_ERROR;
    if(minute > 59 || minute < 0)
        return DATE_ERROR;
    if(second > 59 || second < 0)
        return DATE_ERROR;
    return OK;
}

int days_of_month(const int year, const int month){

    if(year < 1600 || ( month < 1 || month > 12) )
        return DATE_ERROR;
    int days[2][12] =
    {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };

    return days[leap(year)][month - 1];
}

int leap(const int year){
    if(year < 1600)
        return DATE_ERROR;
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;
}

long days_transcurred (t_date *d){
    if(!d)
        return DATE_ERROR;
    if(val_date(d->d,d->m,d->y) == DATE_ERROR)
        return DATE_ERROR;
    int dt = 0;

    for(int i = 1600; i < d->y; i ++){
        dt += 365 + leap(i);
    }

    for(int i = 1; i <= d->m - 1; i++){
        dt += days_of_month(d->y, i);
    }
    return dt + d->d;
}

long difference_days(t_date *d1, t_date *d2){

    if(!d1 || !d2)
        return DATE_ERROR;
    if(val_date(d1->d,d1->m,d1->y) == DATE_ERROR)
        return DATE_ERROR;
    if(val_date(d2->d,d2->m,d2->y) == DATE_ERROR)
        return DATE_ERROR;

    long diff = days_transcurred(d1) - days_transcurred(d2);
    return diff < 0 ? (diff * -1) - 1: diff > 0 ? diff:0;
}

double difference_time(t_date *d1, t_date *d2){

    if(!d1 || !d2)
        return DATE_ERROR;
    if(val_date(d1->d,d1->m,d1->y) == DATE_ERROR)
        return DATE_ERROR;
    if(val_date(d2->d,d2->m,d2->y) == DATE_ERROR)
        return DATE_ERROR;

    double diff_date = difference_days(d1,d2);
    int segundos1 = 0, segundos2 = 0;
    if(d1->hh != d2->hh){
        segundos1 = d1->hh*3600;
        segundos1 += d1->mm * 60;
        segundos1 += d1->ss;
        segundos2 = d2->hh*3600;
        segundos2 += d2->mm * 60;
        segundos2 += d2->ss;

    } else if(d1->mm != d2->mm){
        segundos1 = d1->mm * 60;
        segundos1 += d1->ss;
        segundos2 = d2->mm * 60;
        segundos2 += d2->ss;

    } else {
        segundos1 = d1->ss;
        segundos2 = d2->ss;
    }

    diff_date = diff_date * 3600 * 24;

    diff_date += segundos1 > segundos2 ? segundos1 - segundos2 : segundos2 - segundos1;

    return diff_date;
}

t_date * add_day(t_date *d){

    if(!d)
        return NULL;
    if(val_date(d->d,d->m,d->y) == DATE_ERROR)
        return NULL;
    if(d->m == 12 && d->d == 31){
        d->m = 1;
        d->y = d->y + 1;
        d->d = 1;
    } else {
        int daysOfMonth = days_of_month(d->y,d->m);
        if(d->d + 1 > daysOfMonth){
            d->m ++;
            d->d = 1;
        }else{
            d->d ++;
        }
    }
    return d;
}

t_date * subtract_day(t_date *d){
    if(!d)
        return NULL;
    if(val_date(d->d,d->m,d->y) == DATE_ERROR)
        return NULL;
    if(d->m == 1 && d->d == 1){
        d->d = 31;
        d->m = 12;
        d->y --;
    } else {
        if(d->d == 1){
            d->m --;
            d->d = days_of_month(d->y,d->m);
        } else{
            d->d --;
        }
    }
    return d;
}

t_date * add_days(t_date *d, int days){
    if(!d)
        return NULL;
    if(val_date(d->d,d->m,d->y) == DATE_ERROR)
        return NULL;
    if(days >= 0){
        for(int i = 0; i < days; i++)
            add_day(d);
    } else {
        days *= -1;
        for(int i = 0; i < days; i ++)
            subtract_day(d);
    }
    return d;
}

t_date * subtract_days(t_date *d, int days){
    if(!d)
        return NULL;
    if(val_date(d->d,d->m,d->y) == DATE_ERROR)
        return NULL;
    if(days < 0)
        days *= -1;
    for(int i = 0; i < days; i ++)
        subtract_day(d);
    add_day(d);
    return d;
}

char * name_month(const int month){
    switch(month){
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Nobiembre";
        case 12: return "Diciembre";
    }
    return NULL;
}

char * date_to_string (t_date * f, const int format){
    if(!f)
        return NULL;
    char * fe = (char *)malloc(100);
    if(!fe)
        return NULL;
    switch(format){
        case dd_MM_yyyy:sprintf(fe, "%02d/%02d/%4d", f->d,f->m,f->y);
            break;
        case yyyy_MM_dd: sprintf(fe, "%04d/%02d/%02d", f->y,f->m,f->d);
            break;
        case DESCRIPTIVE: sprintf(fe, "Dia %02d de %s del %4d.", f->d,name_month(f->m),f->y);
            break;
        case DESCRIPTIVE_2: sprintf(fe, "%s %02d del %4d.", name_month(f->m),f->d,f->y);
            break;
        case DESCRIPTIVE_3: sprintf(fe, "%s %02d de %s del %4d.",day_of_week(f),f->d,name_month(f->m),f->y);
            break;
        case DESCRIPTIVE_4: sprintf(fe, "%s %02d de %s del %4d a las %02d:%02d:%02d.",day_of_week(f),f->d,name_month(f->m),f->y,f->hh,f->mm,f->ss);
            break;
    }
    return fe;
}

char * name_day_week(const int nd){
    switch(nd){
        case 0: return "Lunes";
        case 1: return "Martes";
        case 2: return "Miercoles";
        case 3: return "Jueves";
        case 4: return "Viernes";
        case 5: return "Sabado";
        case 6: return "Domingo";
    }
    return NULL;
}

char * day_of_week(t_date * f){
    if(val_date(f->d,f->m,f->y) == DATE_ERROR)
        return NULL;
    unsigned z, a, b, c;
    if (f->m <= 2) {
        a = f->m + 10 ;
        b = (f->y - 1) % 100;
        c = (f->y - 1) / 100;
    } else if (f->m >= 3) {
        a = f->m - 2;
        b = f->y % 100;
        c = f->y / 100;
    }
    z = (700 + (26 * a - 2) / 10 + f->d + b + b / 4  + c / 4 - 2 * c - 1) % 7;
    return name_day_week(z);
}

t_date * date_now(){
    time_t t = time(NULL);

    struct tm localTime = *localtime(&t);
    t_date * d = (t_date *)malloc(sizeof(t_date));

    if(!d)
        return NULL;

    d->d = localTime.tm_mday;
    d->m = localTime.tm_mon + 1;
    d->y = localTime.tm_year + 1900;
    d->hh = localTime.tm_hour;
    d->mm = localTime.tm_min;
    d->ss = localTime.tm_sec;

    return d;
}

t_date * add_hour(t_date *f){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(f->hh == 23) {
        f->hh = 0;
        add_day(f);
    }else {
        f->hh ++;
    }
    return f;
}

t_date * subtract_hour(t_date *f){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(f->hh == 0) {
        f->hh = 23;
        subtract_day(f);
    }else {
        f->hh --;
    }
    return f;
}

t_date * add_hours(t_date * f, const int h){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;

    if(h > 0){
        for(int i = 0; i < h; i++){
            add_hour(f);
        }
    }else if(h < 0){
        for(int i = 0; i < h*-1; i++){
            subtract_hour(f);
        }
    }
    return f;
}

t_date * add_minute(t_date *f){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(f->mm == 59){
        f->mm = 0;
        add_hour(f);
    } else{
        f->mm ++;
    }
    return f;
}

t_date * subtract_minute(t_date *f){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(f->mm == 0){
        f->mm = 59;
        subtract_hour(f);
    } else{
        f->mm --;
    }
    return f;
}

t_date * add_minutes(t_date *f,  const int mins){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(mins > 0){
        for(int i = 0; i < mins; i ++)
            add_minute(f);
    } else if(mins < 0){
        for(int i = 0; i < mins*-1; i ++)
            subtract_minute(f);
    }
    return f;
}

t_date * add_second(t_date *d){
    if(val_time(d->d,d->m,d->y,d->hh,d->mm,d->ss) == DATE_ERROR)
        return NULL;
    if(d->ss == 59){
        d->ss = 0;
        add_minute(d);
    } else d->ss ++;
    return d;
}

t_date * subtract_second(t_date *d){
    if(val_time(d->d,d->m,d->y,d->hh,d->mm,d->ss) == DATE_ERROR)
        return NULL;
    if(d->ss == 0){
        d->ss = 59;
        subtract_minute(d);
    } else d->ss --;
    return d;
}

t_date * add_seconds(t_date *f,  const int secs){
    if(val_time(f->d,f->m,f->y,f->hh,f->mm,f->ss) == DATE_ERROR)
        return NULL;
    if(secs > 0){
        for(int i = 0; i < secs; i ++)
            add_second(f);
    } else if(secs < 0){
        for(int i = 0; i < secs*-1; i ++)
            subtract_second(f);
    }
    return f;
}
