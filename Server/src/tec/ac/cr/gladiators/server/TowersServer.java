package tec.ac.cr.gladiators.server;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;

@Path("populations/towers")
public class TowersServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public int generateTowers(){
        return 2;
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getTowers(){
        System.out.println("Hola");
    }

}
