void read(int* array, int size){
  int endcount = 0;
  while(true){
    for(int i = 0; i< (2*size + 1); ++i){
      char readin;
      scanf(" ");
      scanf("%c", &readin);
      if(readin=='#')
        ++array[i/2];
      else if(readin=='-'){
        ++endcount;
        if(endcount==(2*size+1))
          return;
      }
    }
  }
}

