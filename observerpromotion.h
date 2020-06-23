#ifndef OBSERVERPROMOTION_H
#define OBSERVERPROMOTION_H


class ObserverPromotion
{
public:
    ObserverPromotion(int a);
    virtual void observe() =0;
};

#endif // OBSERVERPROMOTION_H
