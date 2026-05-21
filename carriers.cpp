class Carrier {
protected:
    string type;
public:
    
    virtual double computeCost(double weight) = 0; 
    
    
    virtual int computeDelay(double weight) = 0;

    virtual ~Carrier() {} 
};

class BikeCarrier : public Carrier {
public:
    double computeCost(double weight) override {
        return weight * 0.5; 
    }
    int computeDelay(double weight) override {
        return 30; 
    }
};


class TruckCarrier : public Carrier {
public:
    double computeCost(double weight) override {
        return weight * 1.2;   
    }
    int computeDelay(double weight) override {
        return 120;        
    }
};

// 3. كلاص الدرون (Drone)
class DroneCarrier : public Carrier {
public:
    double computeCost(double weight) override {
        return weight * 5.0; 
    }
    int computeDelay(double weight) override {
        return 15; 
    }
};
