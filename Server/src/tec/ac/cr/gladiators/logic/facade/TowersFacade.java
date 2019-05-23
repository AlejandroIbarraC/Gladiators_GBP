package tec.ac.cr.gladiators.logic.facade;
import tec.ac.cr.gladiators.logic.Towers;
import tec.ac.cr.gladiators.logic.TowersManager;
import java.util.ArrayList;

public class TowersFacade {
    private static TowersManager towersManager = new TowersManager();
    private static ArrayList<Towers> towersList = new ArrayList<>();

    /**
     * Gets the first population of towers
     * @return Initial Population
     */
    public static ArrayList<Towers> initPopulation(){
        towersManager.getPopulation().initializePopulation();
        towersManager.getPopulation().calculateFitness();
        towersList = ArrayToArrayList(towersManager.getPopulation().getIndividuals());
        return towersList;
    }

    /**
     * Update Towers List with a new generation
     * @return Towers List updated
     */
    public static ArrayList<Towers> updatePopulation(){
        towersManager.getPopulation().calculateFitness();
        towersManager.selection();
        towersManager.crossover();
        towersManager.mutation();
        towersManager.updateId();
        towersManager.getPopulation().calculateFitness();
        towersList = ArrayToArrayList(towersManager.getPopulation().getIndividuals());
        return towersList;
    }

    /**
     * Skips a determined number of towers generations.
     * @param i the number of towers to be skipped.
     * @return the new population of towers.
     */
    public static ArrayList<Towers> skipGenerations(int i){
        int y = 0;
        while (y < i-1){
            updatePopulation();
            y++;
        }
        return updatePopulation();
    }
    /**
     * Receive the Tower Array and translate to an Array List
     * @param list Array
     * @return ArrayList
     */
    private static ArrayList<Towers> ArrayToArrayList(Towers[] list){
        ArrayList<Towers> gladiatorsList = new ArrayList<>();
        int length = list.length;
        for (int i=0;i<length;i+=1){
            gladiatorsList.add(list[i]);
        }
        return gladiatorsList;
    }

    public static TowersManager getTowersManager() {
        return towersManager;
    }
}
