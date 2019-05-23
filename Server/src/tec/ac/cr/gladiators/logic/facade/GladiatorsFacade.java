package tec.ac.cr.gladiators.logic.facade;
import tec.ac.cr.gladiators.logic.Gladiators;
import tec.ac.cr.gladiators.logic.GladiatorsManager;

import java.util.ArrayList;
import java.util.Arrays;

public class GladiatorsFacade {
    private static GladiatorsManager gladiatorsManager = new GladiatorsManager();
    private static ArrayList<Gladiators> gladiatorsList = new ArrayList<>();

    /**
     * Gets the first population of gladiators
     * @return Initial Population
     */
    public static ArrayList<Gladiators> initPopulation(){
        gladiatorsManager.getPopulation().initializePopulation();
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsList = ArrayToArrayList(gladiatorsManager.getPopulation().getIndividuals());
        return gladiatorsList;
    }

    /**
     * Update Gladiators List with a new generation
     * @return Gladiator List updated
     */
    public static ArrayList<Gladiators> updatePopulation(){
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsManager.selection();
        gladiatorsManager.crossover();
        gladiatorsManager.mutation();
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsManager.updateId();
        gladiatorsList = ArrayToArrayList(gladiatorsManager.getPopulation().getIndividuals());
        return gladiatorsList;
    }

    /**
     * Skips a determined number of gladiators generations.
     * @param i the number of gladiators to be skipped.
     * @return the new population of gladiators.
     */
    public static ArrayList<Gladiators> skipGenerations(int i){
        int y = 0;
        while (y < i - 1){
            updatePopulation();
            y++;
        }
        return updatePopulation();
    }
    /**
     * Receive the Gladiator Array and translate to an Array List
     * @param list Array
     * @return ArrayList
     */
    private static ArrayList<Gladiators> ArrayToArrayList(Gladiators[] list){
        ArrayList<Gladiators> gladiatorsList = new ArrayList<>();
        gladiatorsList.addAll(Arrays.asList(list));
        return gladiatorsList;
    }

    public static GladiatorsManager getGladiatorsManager() {
        return gladiatorsManager;
    }
}
