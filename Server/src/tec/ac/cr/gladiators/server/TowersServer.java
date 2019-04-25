package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Generator;
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
        return Generator.generateTowers(10);
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getTowers(ArrayList<Towers> towersArrayList){
        System.out.println("4");
    }

}
