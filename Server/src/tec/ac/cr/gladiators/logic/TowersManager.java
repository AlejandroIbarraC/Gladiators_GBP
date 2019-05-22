package tec.ac.cr.gladiators.logic;

import java.util.Random;

public class TowersManager {
    private PopulationT population = new PopulationT();
    private Towers fittest;
    private Towers secondFittest;
    private int generationCount = 0;

    /**
     *Select the two best Gladiators of all the population
     */
    public void selection() {

        //Select the most fittest individual
        fittest = population.getFittest();

        //Select the second most fittest individual
        secondFittest = population.getSecondFittest();
    }

    /**
     * Make a children between the best Gladiators
     */
    public void crossover() {
        Random rn = new Random();

        //Select a random crossover point
        int crossOverPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

        //Swap values among parents
        for (int i = 0; i < crossOverPoint; i++) {
            int temp = fittest.getGenes()[i];
            fittest.getGenes()[i] = secondFittest.getGenes()[i];
            secondFittest.getGenes()[i] = temp;

        }
    }

    /**
     * Search the best gladiator of the population
     * @return Gladiator
     */
    public Towers getFittestOffspring() {
        if (fittest.getFitness() > secondFittest.getFitness()) {
            return fittest;
        }
        return secondFittest;
    }


    /**
     * Replace least fittest individual from most fittest
     */
    public void addFittestOffspring() {

        //Update fitness values of offspring
        fittest.calcFitness();
        secondFittest.calcFitness();

        //Get index of least fit individual
        int leastFittestIndex = population.getLeastFittestIndex();

        //Replace least fittest individual from most fittest offspring
        population.getIndividuals()[leastFittestIndex] = getFittestOffspring();
    }

    /**
     * Try to mutate a random gladiator with a 20% of chance
     */
    public void mutation() {
        Random rn = new Random();

        if (rn.nextInt(100)<= 20){
            System.out.println("A mutation has occurred to Tower: " + this);
            //Select a random mutation point
            int mutationPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

            int mutationValue = rn.nextInt(100);

            while (fittest.getGenes()[mutationPoint] > mutationValue ){
                mutationValue = rn.nextInt(100);
            }
            fittest.getGenes()[mutationPoint] = mutationValue;

            mutationPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

            while (secondFittest.getGenes()[mutationPoint] > mutationValue ){
                mutationValue = rn.nextInt(100);
            }
            secondFittest.getGenes()[mutationPoint] = mutationValue;

        }
    }

    public void updateId(){
        int length = population.getIndividuals().length;
        int i = 0;
        while (i < length){
            population.getIndividuals()[i].setIdentification(i);
            i++;
        }
    }

    public PopulationT getPopulation() {
        return population;
    }

    public void setPopulation(PopulationT population) {
        this.population = population;
    }

    public Towers getFittest() {
        return fittest;
    }

    public void setFittest(Towers fittest) {
        this.fittest = fittest;
    }

    public Towers getSecondFittest() {
        return secondFittest;
    }

    public void setSecondFittest(Towers secondFittest) {
        this.secondFittest = secondFittest;
    }

    public int getGenerationCount() {
        return generationCount;
    }

    public void setGenerationCount(int generationCount) {
        this.generationCount = generationCount;
    }
}
