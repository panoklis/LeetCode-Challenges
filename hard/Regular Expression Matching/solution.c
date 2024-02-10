/*
* Expression is split in tokens (characters including '.')
* '*' information is kept in separate array. eg: a*a == {aa, *_}
*                                                ab*c*a*d. == {abcad.,_***__}
* There is a 'count[length of expression]' array , that keeps how many
*    evaluations there have been of a rule of the expression.
* This array is used to roll back the traversal, whenever there is
*    a nonmatched character, either in the expression, or the string.
* Expression is checked in parallel with the string.
* The rollback 'pulls' characters out of previous multiplier matches,
*    and makes them available to future symbols of the expression.
* If the rollback fails, the expression fails.
*/

int rollback(char* p_e,char* p_m,int* cnt,int off,int *i,int *j,int *k);

bool isMatch(char * s, char * p){
 int i,j,k=-1,l=0,*cnt,len=strlen(s),lenx=strlen(p);
 char *p_e,*p_m;
 p_e=malloc(sizeof(char)*(lenx+1));
 p_m=malloc(sizeof(char)*(lenx+1));

 memset(p_e,(char)(0),lenx+1);
 memset(p_m,(char)(32),lenx+1);

    for(i=0;i<lenx;i++){
        if(p[i]=='*') {p_m[k] = '*';}
        else          {p_e[l] = p[i];l++;k++;}
    }
    p_m[l]=(char)(0);
    lenx=strlen(p_e);
    cnt=malloc(sizeof(int)*lenx);
    for(i=0;i<lenx;i++)
        cnt[i]=0;

    i=j=0;
    while(true){
        if(i<len){
            if(s[i] == p_e[j] || p_e[j]=='.'){
                if(p_m[j] == '*')  {cnt[j]++;i++;}
                else               {cnt[j]++;j++;i++;}
            }
            else if(p_m[j] == '*') {j++;}
            else {
                    if(j-1>0 && p_e[j-1]=='.' && p_m[j-1]!='*'){
                        if(rollback(p_e,p_m,cnt,1,&i,&j,&k)){return false;}    
                    }
                    else{
                        if(rollback(p_e,p_m,cnt,0,&i,&j,&k)){return false;}
                    }
                }
        }
        else if(j<lenx){
            if(p_m[j] != '*') { if (rollback(p_e,p_m,cnt,0,&i,&j,&k)) {return false;} }
            else              {j++;}
        }
        if(j==lenx && i<len) {return false;}
        if(j==lenx && i==len) {return true;}
    }
}

int rollback(char* p_e,char* p_m,int* cnt,int off,int *i,int *j,int *k){
                char chr=p_e[(*j)-off];
                *k=*j-1;
                for(*k;*k>=0;(*k)--){
                    //1. is char && mul
                    if(p_e[*k] == chr || p_e[*k] == '.' || chr == '.'){
                        if(p_m[*k] == '*'){
                            if(cnt[*k]){
                                cnt[*k]--;
                                (*i)--;
                                if(*i<0) {return 1;}
                                break;
                            }
                            (*j)--;
                        }
                    //2. is char && not mul
                        else{
                            cnt[*k]=0;
                            (*i)--;
                            (*j)--;
                        }
                    }
                    //3/4. is not char && (mul or not mul)
                    else{
                         *i-=cnt[*k];
                         cnt[*k]=0;
                         (*j)--;
                    }
                }
                if(*k==-1) {return 1;}
                return 0;
            }