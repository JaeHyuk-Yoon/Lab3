#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void ls_R(char *name){
    DIR *pdir;
    struct dirent *file;
    char tmp[20][200] = {NULL,};
    char *file_path[20] = {NULL,};
    if(!(pdir = opendir(name))) return;
    printf("%s: \n", name);
    int cnt =0, line =0, cnt2 =0;
    
    while((file = readdir(pdir)) !=NULL){
        if(file -> d_type == DT_DIR){
            char path[500];
            if(strcmp(file -> d_name, ".") ==0 || strcmp(file ->d_name, "..") ==0) 
            	continue;
            snprintf(path, sizeof(path), "%s/%s", name, file -> d_name);
            
            for(int i =0; i < strlen(path); i ++){
                tmp[cnt][i] = path[i];
            }
            
            file_path[cnt] = tmp[cnt];
            cnt++;
            printf("%s\t", file_path[cnt -1]);
        } else printf("%s\t", file -> d_name);
        if(line >6){
            printf("\n");
            line =1;
        }
        line ++;
    }
    
    printf("\n");
    printf("\n");
    
        while(file_path[cnt2] !=NULL){
            if(file_path[cnt2] ==NULL) break;
            ls_R(file_path[cnt2]);
            cnt2++;
        }
        
        closedir(pdir);
}

void run(int argc, char *argv[]){
    char dir[500];
    if(argc ==1) strcpy(dir, ".");
    else strcpy(dir, argv[1]);
    ls_R(dir);
}

int main(int argc, char *argv[])
{
    run(argc, argv);
    return 0;
}

