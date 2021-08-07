#include <iostream>
#include <cmath> //math.h
#include <cstdlib>
#define M_PI 3.14159265358979323846  /* pi */
using namespace std;

class Tracking{ 
	private:
		double positionX,positionY;
	public:
		Tracking(double posX,double posY){
		positionX=posX;
		positionY=posY;
		}
		double getX(){ //get functions are used for allowance of access to private data members of this Class (tracking)
		return positionX;
		}
		double getY(){
		return positionY;
		}
};

class Camera{
	private:
		double fPosOnX,fPosOnY,view_ang,view_dis;
		bool isItInTheViewingDistance(Tracking& obj){ //isItInTheViewingDistance boolean func checks if the distance calculated is greater than the view distance, the function returns false
			if(sqrt(pow(obj.getX(),2)+pow(obj.getY(),2))>view_dis)
		  	return 0;
		  	else
     		return 1;  
		}
		bool isItInTheViewingAngle(Tracking& obj2){	//isItInTheViewingAngle boolean func checks if the angle is greater than half of view angle if it is then it returns false
			double angle;
			angle=(acos((fPosOnX*obj2.getX()+fPosOnY*obj2.getY())/(sqrt(pow(fPosOnX,2)+pow(fPosOnY,2))*sqrt(pow(obj2.getX(),2)+pow(obj2.getY(),2)))))*(180/M_PI);
			double half_va=view_ang/2;
			if(angle>half_va)
			return 0;
			else
    		return 1;
		}
	public:
		Camera(double fPX,double fPY, double va,double vd){ //Camera Constructor
		fPosOnX=fPX;
		fPosOnY=fPY;
		view_ang=va;
		view_dis=vd;}
		
		void viewFieldControl(Tracking& obj2){ //viewFieldControl is a void function because it doesnt return but prints...
			if(isItInTheViewingDistance(obj2)==1 && isItInTheViewingAngle(obj2)==1)
			cout<<"Object is in field of view at ("<<obj2.getX()<<","<<obj2.getY()<<")"<<endl;
			else
			cout<<"Object is not in field of view at ("<<obj2.getX()<<","<<obj2.getY()<<")"<<endl;
		}
};

int main(){
	int x,y;
	 for(int i=0;;i++){ //here is the infinite loop in which we have a rand() function working which assigns random numbers for x and y of Tracking object.
   {				   //Infinite loop because task sheet said : "But everytime your program generates those values,they should be generated differently."
    int k=rand()%201; //here rand()%201 generates random numbers between 1 and 200 
	x=k;			 //if the number is less than 100 and greater than 0 then it is assigned to x however if the number is greater than 100 than we subtract 201 as you can see in line 65
  	if(k<=100)		//so the number becomes negative. to generate numbers between -100 and 100 I have come up with this method
  	x=k;
  	else
  	x=k-201;
  	//same random number generation for y
  	k=rand()%201;
  	if(k<=100)
  	y=k;
  	else
  	y=k-201;   
	double a,b,c,d; //for user to input Camera Object variables	
	Tracking tobj(x,y); // Tracking object with randomly generated x and y values between -100 and 100
	cout<<"Enter the forward position of the camera (x,y):";
	cin>>a>>b;
	cout<<"Enter the viewing distance:";
	cin>>c;
	cout<<"Enter the viewing angle:";
	cin>>d;
  	Camera cobj(a,b,c,d);
	cobj.viewFieldControl(tobj);}} //we call the function viewFieldControl here
	return 0;	
}
