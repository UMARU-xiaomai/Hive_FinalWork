#include "aiplayer.h"
#include "game.h"
#include "board.h"
#include <QRandomGenerator>

AIPlayer::AIPlayer(int numOfPlayer,QObject* parent)
    :Player("AI",true,numOfPlayer,parent)
{

}

Piece *AIPlayer::selectPiece()
{
    Piece* res;
    do{
        if(QRandomGenerator::global()->bounded(2))
        {
            int rand_index = QRandomGenerator::global()->bounded(pieces.size());
            res = pieces[rand_index];
        }else
        {
            QVector<Piece*>  tmp;
            for(Board::PieceIterator it = Board::instance->begin();!it.getIsEnd();it++)
            {
                if((*it)&&(*it)->belongingPlayer==this->numberOfPlayer)
                    tmp.push_back(*it);
            }
            if(tmp.size()==0)
                continue;

            int rand_index = QRandomGenerator::global()->bounded(tmp.size());
            res = tmp[rand_index];
        }
    }while(Game::instance->getAvaliablePositions(res).size()==0);
    return res;
}

void AIPlayer::movePiece()
{
    QVector<Cell*> positions = Game::instance->getAvaliablePositions();
    int rand_index = QRandomGenerator::global()->bounded(positions.size());
    Game::instance->setChoosedCell(positions[rand_index]);
}

