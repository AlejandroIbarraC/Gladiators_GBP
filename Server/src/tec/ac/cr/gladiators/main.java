package tec.ac.cr.gladiators;

import tec.ac.cr.gladiators.logic.Holder;
import tec.ac.cr.gladiators.logic.facade.GladiatorsFacade;
import tec.ac.cr.gladiators.logic.facade.TowersFacade;

public class main {

    public static void main(String args[]){
        TowersFacade.initPopulation();
        TowersFacade.skipGenerations(100);
        TowersFacade.updatePopulation();

        Holder.gladiatorsArrayList = GladiatorsFacade.initPopulation();
        Holder.gladiatorsArrayList = GladiatorsFacade.skipGenerations(100);
        Holder.gladiatorsArrayList = GladiatorsFacade.updatePopulation();
        Holder.gladiatorsArrayList = GladiatorsFacade.initPopulation();

    }

}
