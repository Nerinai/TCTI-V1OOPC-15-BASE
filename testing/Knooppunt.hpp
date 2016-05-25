#ifndef KNOOPPUNT_HPP
#define KNOOPPUNT_HPP


class coordinaat{
private:
	float x;
	float y;
public:
	coordinaat(float x; float y):
		x ( x ),
		y ( y )
		{}
};

class knoopunt{
public: 
	coordinaat plek;
	
	knoopunt (coordinaat plek):
	plek (plek)
	{}
};

class verbinding{
private:
	knoopunt & start, & enide;
	float lengte;
	
public:
	verbinding(knoopunt & start, knoopunt & einde, float lengte)
	{}
	
	float efficency(const knoopunt & start, const knoopunt & einde) const {
		coordinaat verschil = start.plek - einde.plek;
		float rechte_lijn =  sqrt(kwadraat(verschil.getx) + kwadraat(verschil.gety));
		return (lengte / rechte lijn);

};

// een - operator voor coordinaat
// een get functie in coordinaat

#endif


