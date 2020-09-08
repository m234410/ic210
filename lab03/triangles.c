/* Daniel Murray*/

#include"ic210.h"
#include<math.h>

int main(){
  fputs("Enter side lengths: ", stdout);
  double side1 = readnum(stdin);
  double side2 = readnum(stdin);
  double side3 = readnum(stdin);
  char typeAngle = 'n';
  char typeSide = 'n';
  double s = 0.5*(side1 + side2 +side3);
  double area = sqrt(s*(s - side1)*(s - side2)*(s - side3));
  double angle1 = asin((2*area*side1)/(side1*side2*side3));
  double angle2 = asin((2*area*side2)/(side1*side2*side3));
  double angle3 = asin((2*area*side3)/(side1*side2*side3));

  if(angle1+angle2+angle3<M_PI){
    if(side1 > side2 && side1 > side3)
      angle1 = M_PI-angle1;
    if(side2 > side1 && side2 > side3)
      angle2 = M_PI-angle2;
    if(side3 > side1 && side3 > side2)
      angle3 = M_PI-angle3;
  }

  
  if(side1+side2<=side3||side1+side3<=side2||side2+side3<=side1){
    fputs("These lengths violate the triangle inequality!", stdout);
    return 0;
  }
  if(angle1==M_PI/2 || angle2==M_PI/2 || angle3==M_PI/2)
    typeAngle = 'r';
  else if(angle1>M_PI/2 || angle2>M_PI/2 || angle3>M_PI/2)
    typeAngle = 'o';
  else if(angle1<M_PI/2 || angle2<M_PI/2 || angle3<M_PI/2)
    typeAngle = 'a';

  if(side1==side2&&side2==side3)
    typeSide = 'e';
  else if(side1==side2||side1==side3||side2==side3)
    typeSide = 'i';
  else 
    typeSide = 's';

  fputs("This is ", stdout);
  if(typeAngle == 'a')
    fputs("an acute ", stdout);
  else if(typeAngle == 'o')
    fputs("an obtuse ", stdout);
  else if(typeAngle == 'r')
    fputs("a right ", stdout);
  
  if(typeSide == 's')
    fputs("scalene ", stdout);
  else if(typeSide == 'i')
    fputs("isosceles ", stdout);
  else if(typeSide == 'e')
    fputs("equilateral ", stdout);
  
  fputs("triangle.", stdout);


  
  return 0;
}

