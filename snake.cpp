#include "gamefeatures.cpp"

class BodyPart : public GameObject
{
public:
    BodyPart(GamePos p, Direction d) : GameObject(p, d)
    {
        nextPart = nullptr;
    }

    BodyPart *getNextPart()
    {
        return nextPart;
    }

    void appendPart(BodyPart* n)
    {
        nextPart = n;
    }

private:
    BodyPart *nextPart;
};

class Snake
{
public:
    Snake(GamePos p, Direction d)
    {
        head = new BodyPart(p, d);
        tail = head;
    }

    void move()
    {
        BodyPart *aux = tail;
        tail = tail->getNextPart();
        delete aux;

        GamePos headCurrentPosition = head->getPos();
        Direction headCurrentDirection = head->getDir();

        aux = new BodyPart(headCurrentPosition, headCurrentDirection);
        aux->appendPart(*head);
        head = aux;
    }

    void draw(void (*callback)(int x, int y))
    {
        BodyPart *current = head;
        GamePos pos;
        while (current != 0)
        {
            pos = current->getPos();
            callback(pos.getX(), pos.getY());
        }
    }

private:
    BodyPart *head;
    BodyPart *tail;

    void addHead()
    {
        BodyPart *part = new BodyPart(head->getPos(), head->getDir());

        head->appendPart(part);
        head = part;
    }
};