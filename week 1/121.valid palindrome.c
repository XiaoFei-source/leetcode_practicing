bool isPalindrome(char *s){
    char *arr = (char*)calloc(strlen(s)+1,sizeof(char));
    int i = 0, index = 0 ,j = 0,len = strlen(s);
    while(*s!= '\0')
    {
        if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') || (*s >= '0' && *s <= '9'))
        {
            if(*s >= 'A' && *s <= 'Z')
                arr[index++] = *s + 'a' - 'A';
            else
                arr[index++] = *s;
        }
        s++;
    }
    arr[index]='\0';
    for(i = 0,j = index-1;i<j;i++,j--){
        if(arr[i]!=arr[j])
            return false;
    }
    return true;
}
