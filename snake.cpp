#include "gamefeatures.cpp"

class BodyPart : public GameObject{
    public:
        BodyPart(GamePos p, Direction d):GameObject(p, d)
        {
            nextPart = 0;
        }
        BodyPart* getNextPart()
        {
            return nextPart;
        }

        void appendPart(BodyPart n)
        {
            nextPart = &n;
        }

    private:
        BodyPart *nextPart;
};

class Snake {
    public:

        Snake(GamePos p, Direction d)
        {
            head = new BodyPart(p, d);
            tail = head;
        }

        void move() {
            BodyPart *aux = tail;
            tail = tail->getNextPart();
            delete aux;
            
            GamePos newPos = head->getPos(); 

            if(currentDirection.isToDown()) newPos.incrementY();
            if(currentDirection.isToUp()) newPos.decrementY();
            if(currentDirection.isToLeft()) newPos.decrementX();
            if(currentDirection.isToRigth()) newPos.incrementX();

            aux = new BodyPart(newPos, currentDirection);
            aux->appendPart(*head);
            head = aux;
        }

        void removePart()
        {
            BodyPart* aux = tail;

            if(head == tail)
            {
                tail = head = nullptr;
            }
            else 
            {
                tail = tail->getNextPart();
            }
            
            delete aux;
        }

        void changeDirection(Direction newDirection)
        {
            currentDirection = newDirection;
        }

        void draw(void (*callback)(int x, int y)) 
        {
            BodyPart*current = tail;
            GamePos pos;
            while (current!=0) {
                pos = current->getPos();
                callback(pos.getX(), pos.getY());          
            }
        }

    private:
        BodyPart *head;
        BodyPart *tail;
        Direction currentDirection;  
};