#include <stdlib.h>
#include <string.h>
void executeCommands(char* comment, char * branch );
int main(int argc, char** argv) {
    (argv[1] != NULL && argv[2] != NULL ) ? executeCommands((char *)argv[1], (char *)argv[2]) : executeCommands((char *) "upgrade code", (char *) "master");
    return 0;
}
void executeCommands(char *comment, char * branch){
    /* varibile  */
    char commit[100] = "git commit -m \"";
    char pull [50] = "git pull origin ";
    char push [50] = "git push -u origin ";
    /* concat string  */
    if(comment != "upgrade code"){
        strcat(comment, "\"");
    }
    strcat(commit, comment);
    strcat(pull, branch);
    strcat(push, branch);
    /* command for git  */
    system(pull);
    system("git add .");
    system((char*)commit);
    system(push);
}