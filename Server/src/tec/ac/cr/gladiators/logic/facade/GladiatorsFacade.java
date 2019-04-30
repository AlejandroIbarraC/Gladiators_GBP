package tec.ac.cr.gladiators.logic.facade;
import tec.ac.cr.gladiators.logic.Gladiators;
import tec.ac.cr.gladiators.logic.GladiatorsManager;
import java.util.ArrayList;

public class GladiatorsFacade {
    private static GladiatorsManager gladiatorsManager = new GladiatorsManager();
    private static ArrayList<Gladiators> gladiatorsList = new ArrayList<>();

    public static ArrayList<Gladiators> initPopulation(){
        gladiatorsManager.getPopulation().initializePopulation();
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsList = ArrayToArrayList(gladiatorsManager.getPopulation().getIndividuals());
        return gladiatorsList;
    }

    public static ArrayList<Gladiators> updatePopulation(ArrayList<Gladiators> list){
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsManager.selection();
        gladiatorsManager.mutation();
        gladiatorsManager.addFittestOffspring();
        gladiatorsManager.getPopulation().calculateFitness();
        gladiatorsList = ArrayToArrayList(gladiatorsManager.getPopulation().getIndividuals());
        return gladiatorsList;
    }

    private static ArrayList<Gladiators> ArrayToArrayList(Gladiators[] list){
        ArrayList<Gladiators> gladiatorsList = new ArrayList<>();
        int length = list.length;
        for (int i=0;i<length;i+=1){
            gladiatorsList.add(list[i]);
        }
        return gladiatorsList;
    }

    public static GladiatorsManager getGladiatorsManager() {
        return gladiatorsManager;
    }
}
