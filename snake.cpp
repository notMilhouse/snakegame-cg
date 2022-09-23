class GamePos {
    public:
        GamePos() {
            posX = 15;
            posY = 15;
        }

        GamePos(int x, int y) {
            posX = x;
            posY = y;
        }

        void setPos(int x, int y) {
            posX = x;
            posY = y;
        }

        int getX() {
            return posX;
        }

        int getY() {
            return posY;
        }

        void incrementX() {
            posX++;
        }

        void incrementY() {
            posY++;
        }

        void incrementX(int increment) {
            posX += increment;
        }

        void incrementY(int increment) {
            posY += increment;
        }
    
    private:
        int posX;
        int posY;
};

class Direction {
    public:
        Direction() {
            dirX = 1;
            dirY = 0;
        }

        void toUp() {
            dirX = 0;
            dirY = 1;
        }

        void toDown() {
            dirX = 0;
            dirY = -1;
        }

        void toLeft() {
            dirX = -1;
            dirY = 0;
        }

        void toRight() {
            dirX = 1;
            dirY = 0;
        }

    private:
        short dirX;
        short dirY;
};

class BodyPart {
    public:
        void appendPart();
    private:
        GamePos pos;
        BodyPart *nextPart;
};

class Snake {
    public:
        void move() {

        }

        void draw() {

        }

        GamePos getPos();

    private:
        BodyPart head;
        Direction currentDirection;
    
};