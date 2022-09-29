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

    void appendPart(BodyPart *n)
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
        addHead();
        removeTail();
    }

    void changeDirection(DirectionState newState)
    {
        switch (newState)
        {
            case DirectionState::RIGHT:
                head->getDir().toRight();
                break;
            case DirectionState::LEFT:
                head->getDir().toLeft();
                break;
            case DirectionState::UP:
                head->getDir().toUp();
                break;
            case DirectionState::DOWN:
                head->getDir().toDown();
                break;
            
            default:
                break;
        }
    }

    void draw(void (*callback)(int x, int y))
    {
        BodyPart *current = tail;
        GamePos pos;
        while (current != nullptr)
        {
            pos = current->getPos();
            callback(pos.getX(), pos.getY());
            current = current->getNextPart();
        }
    }

private:
    BodyPart *head;
    BodyPart *tail;

    void addHead()
    {
        GamePos currentPos = head->getPos();
        Direction currentDir = head->getDir();

        GamePos* newPos = currentPos
            .incrementX(head->getDir().getDirX())
            ->incrementY(head->getDir().getDirY());
        

        BodyPart *part = new BodyPart(*newPos, currentDir);

        head->appendPart(part);
        head = part;
    }


    void removeTail()
    {
        BodyPart *aux = tail;

        if (head == tail)
        {
            tail = head = nullptr;
        }
        else
        {
            tail = tail->getNextPart();
        }

        delete aux;
    }
};