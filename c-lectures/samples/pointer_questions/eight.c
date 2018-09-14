int main(int argc, char** argv)
{
 char *ptr = "PointersAreFreakingCool";
 printf("%cn", *&*&*ptr);
 return 0;
}
