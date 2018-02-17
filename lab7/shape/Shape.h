//
// Created by Kinga on 24.04.2017.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H


class Ksztalt {

public:
    ~Ksztalt();
    virtual void Rysuj()const=0;
};

class Kolo : public Ksztalt
{
public:
    ~Kolo();
    virtual void Rysuj()const override;
};

class Trojkat : public Ksztalt
{
public:
    ~Trojkat();
    virtual void Rysuj()const override;
};

class Kwadrat : public Ksztalt
{
public:
    ~Kwadrat();
    virtual void Rysuj()const override;
};

#endif //JIMP_EXERCISES_SHAPE_H
