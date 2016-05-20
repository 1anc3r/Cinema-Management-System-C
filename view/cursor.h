int Cursor(int up,int down,int left,int right,int backspace,int step);

int Cursor(int up,int down,int left,int right,int backspace,int step)
{
    char ch;
    int line=up;
    Position(left,line);
    printf(">>");
    Position(right,line);
    printf("<<");
    while((ch=getch())!=0x0d)
    {
        while(ch==0x48)
        {
            if(line==up)
            {
                break;
            }
            else
            {
                Position(left,line);
                printf("  ");
                Position(right,line);
                printf("  ");
                line-=step;
                Position(left,line);
                printf(">>");
                Position(right,line);
                printf("<<");
                break;
            }
        }
        while(ch==0x50)
        {
            if(line==down)
            {
                break;
            }
            else
            {
                Position(left,line);
                printf("  ");
                Position(right,line);
                printf("  ");
                line+=step;
                Position(left,line);
                printf(">>");
                Position(right,line);
                printf("<<");
                break;
            }
        }
        if(ch==0x1b)
        {
            line=backspace;
            break;
        }
    }
    return line;
}
