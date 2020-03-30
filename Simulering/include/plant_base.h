class PlantBase
{
private:
    /* data */
public:
   virtual double getHeight() = 0;
   virtual void grow(int days) = 0;
};