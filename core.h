#ifndef CORE_H
#define CORE_H

#include <string>

// بنية الطرد (Données du Colis)
struct Package {
    double weight;
    bool isFragile;
};

// الكلاس الأم المجرد للناقل (Interface Abstraite)
class Carrier {
public:
    virtual ~Carrier() {}
    
    // دوال افتراضية نقية يجب على كل ناقل تطبيقها بمنطقه الخاص
    virtual bool canDeliver(const Package& p) const = 0;
    virtual double computeCost(const Package& p) const = 0;
    virtual std::string getName() const = 0;
    virtual int getDelay() const = 0; // الوقت المستغرق بالديرق (مثلاً بالأيام أو الساعات)
};

#endif // CORE_H
