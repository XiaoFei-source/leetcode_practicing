bool isValid(char* s){
    int stack[100000];
    int flag = -1;
    while(*s){
        if(')'==*s){
            if(flag >= 0 && stack[flag--] == '(');
            //這邊的if敘述多了'的if敘述多了';'分號，代表條件成立時，後面敘述也不執行。
            //stack[flag--] 表示取出堆疊頂部的元素，同時將 flag 減一。
            else{
                return false;
            }
        }
        else if(']'==*s){
            if(flag >= 0 && stack[flag--] == '[');
            else{
                return false;
            }
        }

        else if('}'==*s){
            if(flag >= 0 && stack[flag--] == '{');
            else{
                return false;
            }
        }

        else {
            stack[++flag] = *s;
        }
        s++;
    }
    return -1 == flag;

}