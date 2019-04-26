package tec.ac.cr.gladiators.logic;
import java.util.Random;


public class Population {
    int popSize = 10;
    Gladiators[] individuals = new Gladiators[10];
    private int fittest = 0;


    public void initializePopulation() {
        for (int i = 0; i < individuals.length; i++) {
            individuals[i] = Gladiators.getGladiator(i);
        }
    }

    //Get random Gladiator

    public  Gladiators getRandomGladiator(){
        Random rn = new Random();
        //Select a random crossover point
        int randomIndex = rn.nextInt(this.individuals.length);

        if(individuals[randomIndex] != this.getFittest()){
            return individuals[randomIndex];
        }else{
            return this.getRandomGladiator();
        }
    }

    //Get the fittest individual
    public Gladiators getFittest() {
        int maxFit = 0;
        int maxFitIndex = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (maxFit <= individuals[i].getFitness()) {
                maxFit = individuals[i].getFitness();
                maxFitIndex = i;
            }
        }
        this.fittest = individuals[maxFitIndex].getFitness();
        return individuals[maxFitIndex];
    }

    //Get the second most fittest individual
    public Gladiators getSecondFittest() {
        int maxFit1 = 0;
        int maxFit2 = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (individuals[i].getFitness() > individuals[maxFit1].getFitness()) {
                maxFit2 = maxFit1;
                maxFit1 = i;
            } else if (individuals[i].getFitness() > individuals[maxFit2].getFitness()) {
                maxFit2 = i;
            }
        }
        return individuals[maxFit2];
    }

    //Get index of least fittest individual
    public int getLeastFittestIndex() {
        int minFitVal = Integer.MAX_VALUE;
        int minFitIndex = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (minFitVal >= individuals[i].getFitness()) {
                minFitVal = individuals[i].getFitness();
                minFitIndex = i;
            }
        }
        return minFitIndex;
    }

    //Calculate fitness of each individual
    public void calculateFitness() {

        for (int i = 0; i < individuals.length; i++) {
            individuals[i].calcFitness();
        }
        getFittest();
        getSecondFittest();

    }

    public void setFittest(int fittest) {
        this.fittest = fittest;
    }

    public int getFittestValue(){
        return  this.fittest;
    }
}