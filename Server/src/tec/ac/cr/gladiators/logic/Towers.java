package tec.ac.cr.gladiators.logic;

import java.util.Random;

public class Towers {

    Towers(int identification, int typeOfTheAmmo, int damageOfTheAmmo, int rangeOfTheAmmo, int deaths) {
        this.identification = identification;
        this.typeOfAmmo = typeOfTheAmmo;
        this.damageOutput = damageOfTheAmmo;
        this.range = rangeOfTheAmmo;
        this.deaths = deaths;
    }

    public static Towers addTowers(int identification) {
        Random rn = new Random();
        Towers tower = new Builder().setIdentification(identification)
                .typeOfAmmo(rn.nextInt(3))
                .damageOutput(rn.nextInt(100))
                .range(rn.nextInt(5)).build();
        tower.fillGenes();
        return tower;
    }

    private void fillGenes() {
        int[] genes = new int[3];
        genes[0] = this.getTypeOfAmmo();
        genes[1] = this.getDamageOutput();
        genes[2] = this.getRange();
        this.setGenes(genes);
    }

    public void calcFitness() {
        int fit = 0;
        for (int i = 0; i < this.getGenes().length; i++) {
            fit += genes[i];
        }
        this.setFitness(fit);
    }

    private int identification;
    private int typeOfAmmo;
    private int damageOutput;
    private int range;
    private int deaths;
    private int fitness = 0;
    private int[] genes = new int[3];

    public int getIdentification () {
        return identification;
    }

    public void setIdentification(int identification){
        this.identification = identification;
    }

    public int getTypeOfAmmo () {
        return typeOfAmmo;
    }

    public void setTypeOfAmmo ( int typeOfAmmo){
        this.typeOfAmmo = typeOfAmmo;
    }

    public int getDamageOutput () {
        return damageOutput;
    }

    public void setDamageOutput ( int damageOutput){
        this.damageOutput = damageOutput;
    }

    public int getRange () {
        return range;
    }

    public void setRange ( int range){
        this.range = range;
    }

    public int getFitness() {
        return fitness;
    }

    public void setFitness(int fitness) {
        this.fitness = fitness;
    }

    public int[] getGenes () {
        return genes;
    }

    public void setGenes ( int[] genes){
        this.genes = genes;
    }

    public static class Builder {
        private int identification;
        private int typeOfAmmo;
        private int damageOutput;
        private int range;
        private int deaths;


        public Builder() {}

        public Builder typeOfAmmo(int typeOfAmmo) {
            this.typeOfAmmo = typeOfAmmo;
            return this;
        }

        public Builder damageOutput(int damageOutput) {
            this.damageOutput = damageOutput;
            return this;
        }

        public Builder range(int range) {
            this.range = range;
            return this;
        }

        public Builder deaths(int deaths) {
            this.deaths = deaths;
            return this;
        }
        public Builder setIdentification(int identification){
            this.identification = identification;
            return this;
        }


        public Towers build() {
            return new Towers(identification, typeOfAmmo, damageOutput, range, deaths);
        }
    }

    }
