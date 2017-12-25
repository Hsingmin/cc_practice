
//使用C方式处理内存分配错误 
ptr=new(nothrow) int[intNums];
if(ptr==NULL)
{
  cerr<<"Unable to allocate memory!/n"<<endl;
  return ;             
}
