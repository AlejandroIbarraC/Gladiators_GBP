package tec.ac.cr.gladiators.logic;

import java.util.Random;

public class Gladiators {

    Gladiators(int identification, int ageNumber, int probability, int gensToSurvive,
               int emotionInteligence, int condition, int strenghtUT, int strenghtLT,
               int calculatedResistence){
        this.id = identification;
        this.age = ageNumber;
        this.survivalProbability = probability;
        this.howManyGensWillSurvive = gensToSurvive;
        this.emotionalInteligence = emotionInteligence;
        this.physicalCondition = condition;
        this.strenghtInUpperTrunk = strenghtUT;
        this.strenghtInLowerTrunk = strenghtLT;
        this.resistence = calculatedResistence;
    }

    private int id;
    private int age;
    private int survivalProbability;
    private int howManyGensWillSurvive;
    private int emotionalInteligence;
    private int physicalCondition;
    private int strenghtInUpperTrunk;
    private int strenghtInLowerTrunk;
    private int resistence;

    private int fitness = 0;
    private int[] genes = new int[9];

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getSurvivalProbability() {
        return survivalProbability;
    }

    public void setSurvivalProbability(int survivalProbability) {
        this.survivalProbability = survivalProbability;
    }

    public int getHowManyGensWillSurvive() {
        return howManyGensWillSurvive;
    }

    public void setHowManyGensWillSurvive(int howManyGensWillSurvive) {
        this.howManyGensWillSurvive = howManyGensWillSurvive;
    }

    public int getEmotionalInteligence() {
        return emotionalInteligence;
    }

    public void setEmotionalInteligence(int emotionalInteligence) {
        this.emotionalInteligence = emotionalInteligence;
    }

    public int getPhysicalCondition() {
        return physicalCondition;
    }

    public void setPhysicalCondition(int physicalCondition) {
        this.physicalCondition = physicalCondition;
    }

    public int getStrenghtInUpperTrunk() {
        return strenghtInUpperTrunk;
    }

    public void setStrenghtInUpperTrunk(int strenghtInUpperTrunk) {
        this.strenghtInUpperTrunk = strenghtInUpperTrunk;
    }

    public int getStrenghtInLowerTrunk() {
        return strenghtInLowerTrunk;
    }

    public void setStrenghtInLowerTrunk(int strenghtInLowerTrunk) {
        this.strenghtInLowerTrunk = strenghtInLowerTrunk;
    }

    public int getResistence() {
        return resistence;
    }

    public void setResistence(int resistence) {
        this.resistence = resistence;
    }

    public int getFitness() {
        return fitness;
    }

    public void setFitness(int fitness) {
        this.fitness = fitness;
    }

    public int[] getGenes() {
        return genes;
    }

    public void setGenes(int[] genes) {
        this.genes = genes;
    }

    public static Gladiators addGladiator(int id){
        Random rn = new Random();
        Gladiators gladiator = new Builder().setId(id).setAge(rn.nextInt(100))
                .setSurvivalProbability(rn.nextInt(100))
                .setHowManyGensWillSurvive(rn.nextInt(100))
                .setEmotionalInteligence(rn.nextInt(100))
                .setPhysicalCondition(rn.nextInt(100))
                .setStrenghtInUpperTrunk(rn.nextInt(100))
                .setStrenghtInLowerTrunk(rn.nextInt(100))
                .setResistence(rn.nextInt(100)).build();
        gladiator.fillGenes();
        return gladiator;
    }

    private void fillGenes(){
        int[] genes = new int[8];
        genes[0] = this.getAge();
        genes[1] = this.getSurvivalProbability();
        genes[2] = this.getHowManyGensWillSurvive();
        genes[3] = this.getEmotionalInteligence();
        genes[4] = this.getPhysicalCondition();
        genes[5] = this.getStrenghtInUpperTrunk();
        genes[6] = this.getStrenghtInLowerTrunk();
        genes[7] = this.getResistence();
        this.setGenes(genes);
    }

    //Calculate fitness
    public void calcFitness() {
        int fit = 0;
        for (int i = 0; i < this.getGenes().length; i++) {
            fit += genes[i];
        }
        this.setFitness(fit);
    }

    public static class Builder {

        private int id;
        private int age;
        private int survivalProbability;
        private int howManyGensWillSurvive;
        private int emotionalInteligence;
        private int physicalCondition;
        private int strenghtInUpperTrunk;
        private int strenghtInLowerTrunk;
        private int resistence;

        public Builder(){}

        public Builder setId(int id) {
            this.id = id;
            return this;
        }

        public Builder setAge(int age) {
            this.age = age;
            return this;
        }

        public Builder setSurvivalProbability(int survivalProbability) {
            this.survivalProbability = survivalProbability;
            return this;
        }

        public Builder setHowManyGensWillSurvive(int howManyGensWillSurvive){
            this.howManyGensWillSurvive = howManyGensWillSurvive;
            return this;
        }

        public Builder setEmotionalInteligence(int emotionalInteligence){
            this.emotionalInteligence = emotionalInteligence;
            return this;
        }

        public Builder setPhysicalCondition(int physicalCondition){
            this.physicalCondition = physicalCondition;
            return this;
        }

        public Builder setStrenghtInUpperTrunk(int strenghtInUpperTrunk){
            this.strenghtInUpperTrunk = strenghtInUpperTrunk;
            return this;
        }

        public Builder setStrenghtInLowerTrunk(int strenghtInLowerTrunk){
            this.strenghtInLowerTrunk = strenghtInLowerTrunk;
            return this;
        }

        public Builder setResistence(int resistence){
            this.resistence = resistence;
            return this;
        }


        public Gladiators build() {

            return new Gladiators(id, age, survivalProbability, howManyGensWillSurvive,
                    emotionalInteligence, physicalCondition, strenghtInUpperTrunk, strenghtInLowerTrunk,
                    resistence);

        }
    }

}