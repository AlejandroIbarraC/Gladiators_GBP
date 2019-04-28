package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Generator;
import tec.ac.cr.gladiators.logic.Holder;
import tec.ac.cr.gladiators.logic.Towers;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;

@Path("populations/towers")
public class TowersServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Towers> generateTowers(){
        System.out.println(3);
        if (Holder.towersArrayList == null){
            return Generator.generateTowers(10);
        }
        return Holder.towersArrayList;
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getTowers(ArrayList<Towers> towersArrayList){
        System.out.println("4");
        //Agregar fitness aqui
        Holder.towersArrayList = towersArrayList;
    }

}
