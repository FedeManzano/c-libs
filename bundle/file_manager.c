#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"


int open_file_(t_file * file, const char *path, const char *mode)
{
    *file = fopen(path,mode);
    if(!*file)
        return _OPEN_FILE_ERROR;
    return _OPEN_FILE_OK;
}

t_file open_file(const char *path, const char *mode)
{
    FILE * file = fopen(path,mode);
    return file;
}

int show_file(const char *path, t_show_record record,const size_t size)
{
    t_file file = fopen(path,"rb");

    if(!file)
        return _OPEN_FILE_ERROR;

    void *info = malloc(size);
    if(!info)
        return 0;

    fread(info,size,1,file);

    while(!feof(file))
    {
        record(info);
        fread(info,size,1,file);
    }
    fclose(file);
    free(info);
    return 1;
}

int show_file_(t_file *file, t_show_record record,const size_t size)
{
    if(!*file)
        return _OPEN_FILE_ERROR;

    void *info = malloc(size);
    if(!info)
        return 0;

    fread(info,size,1,*file);

    while(!feof(*file))
    {
        record(info);
        fread(info,size,1,*file);
    }
    free(info);
    return 1;
}

long file_bytes_ (t_file *file)
{
    if(!*file)
        return 0;
    fseek(*file,0L,SEEK_END);
    long cbyte = ftell(*file);
    fseek(*file,0L,SEEK_SET);
    return cbyte;
}

long file_bytes(const char *path)
{
    FILE *file = open_file(path,"rb");
    if(!file)
        return 0;
    fseek(file,0L,SEEK_END);
    long cbyte = ftell(file);
    file_close(&file);
    return cbyte;
}

long file_records_ (t_file *file, size_t size)
{
    if(size <= 0)
        return 0;
    return file_bytes_(file) / size;
}

long file_records (const char *path, size_t size)
{
    if(size <= 0)
        return 0;
    return file_bytes(path) / size;
}

void file_close(t_file *file)
{
    fclose(*file);
}
