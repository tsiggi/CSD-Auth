class Triangle
{
  private:
    float xa;
    float ya;
    float xb;
    float yb;
    float xc;
    float yc;
  public:
    Triangle();
    Triangle (float,float,float,float,float,float) ;
    void SetXA(float);
    void SetYA(float);
    void SetXB(float);
    void SetYB(float);
    void SetXC(float);
    void SetYC(float);
    float getAB();
    float getAC();
    float getBC();
    float getA();
    float getB();
    float getC();
    bool isIsopleurous();
    bool isIsosceles();
    bool isScalino();
    bool isOrthogonio();
    bool isOxygonio();
    bool isAmvligonio();
    float getHeight();
    float getBase();
    float getArea();
};