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

        void decrementX() {
            posX--;
        }

        void decrementY() {
            posY--;
        }

        void decrementX(int increment) {
            posX -= increment;
        }

        void decrementY(int increment) {
            posY -= increment;
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

        void stop()
        {
            dirX = 0;
            dirY = 0;
        }

        bool isToUp()
        {
            if (dirX == 1 && dirY == 0)
                return true;

            return false;
        }

        bool isToDown()
        {
            if (dirX == 1 && dirY == 0)
                return true;

            return false;
        }

        bool isToLeft()
        {
            if (dirX == 1 && dirY == 0)
                return true;

            return false;
        }

        bool isToRigth()
        {
            if (dirX == 1 && dirY == 0)
                return true;

            return false;
        }
        
    private:
        short dirX;
        short dirY;
};

class GameObject {
    public:
        GameObject(GamePos p, Direction d)
        {
            pos = p;
            direction = d;
        };
        GameObject(GamePos p);
        GameObject(Direction d);
        GameObject();

        GamePos getPos()
        {
            return pos;
        }

        static void draw();

    protected:
        GamePos pos;
        Direction direction;
};