package assignment1;

//Import Dependencies
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException; 
import java.text.DecimalFormat;

public class Main {
	public static void main(String args[]) throws IOException {

		//File
		BufferedReader br = new BufferedReader(new FileReader("shapes.txt"));
		//Format to 2 decimals
		DecimalFormat f = new DecimalFormat("0.00");

		//Line by line
		String line = br.readLine();
		
		//shapeDetails will hold every shape 
		String[] shapeArray = new String[43];
		int i = 0;
		while (line != null) {
			shapeArray[i] = line;
			line = br.readLine();
			i++;
		}
		br.close();
		//Keep totals
		double totalParallelogramPer = 0;
		double totalTrianglePer= 0;
		
		//Compare sizes
		double triangleMinimum = 1000; 
		double circleMaximum = 0;
		
		//Print Introduction
		System.out.println("==========> Assignment 1 ");
		System.out.println("==========> Name:\n");
		System.out.println("==========> Task 1 <==========");
		
		//Using rounding to 2
		System.out.println("===> Rounding to 2 spaces <=== \n");
		
		//Keep track of the total of the shapes
		int currentCount = 0;
		for (String s1: shapeArray) {
			//if line not empty
			if(s1 != null){
				//Split by commas
				String[] shapeParts = s1.split(",");
				
				//Circle Case
				if(shapeParts[0].equals("Circle")){
					Circle newCircle = new Circle();
					double tempRadius = Double.parseDouble(shapeParts[1]);
					if(tempRadius > 0){
						newCircle.setRadius(Double.parseDouble(shapeParts[1]));
						currentCount++;
					}
					else{
						System.out.println("This circle has invalid values => r=" + tempRadius);
						continue;
					}
					
					System.out.println("Circle ---------> { r = " + shapeParts[1] + " } perimeter = " + f.format(newCircle.perimeter()));
					
					//If current perimeter is bigger it will become the maximum
					if(newCircle.perimeter() >= circleMaximum){
						circleMaximum =  newCircle.perimeter();
					}
					
				//Square case	
				}else if(shapeParts[0].equals("Square")){
					try{
						
						Square newSquare = new Square();
						double tempLength = Double.parseDouble(shapeParts[1]);
						if(tempLength > 0){
							newSquare.setLength(Double.parseDouble(shapeParts[1]));
							currentCount++;
						}
						else{
							System.out.println("This square has invalid values => l=" + tempLength);
							continue;
						}
						
						System.out.println("Square ---------> { l = " + shapeParts[1] + " } perimeter = " + f.format(newSquare.perimeter()));

					}catch (Exception e) {
						continue;
					}
					
				//Rectangle case	
				}else if((shapeParts[0].equals("Rectangle"))){
					
					try{
						Rectangle newRectangle = new Rectangle();
						double tempLength = Double.parseDouble(shapeParts[1]);
						double tempWidth = Double.parseDouble(shapeParts[2]);
						if(tempLength > 0 && tempWidth > 0){
							newRectangle.setLength(tempLength);
							newRectangle.setWidth(tempWidth);
							currentCount++;
						}
						else{
							System.out.println("This rectangle has invalid values => l=" + tempLength + " ,w=" + tempWidth);
							continue;
						}
						

						System.out.println("Rectangle ------> { l = " + shapeParts[1] + " w = " + shapeParts[2] + " } perimeter = " + f.format(newRectangle.perimeter()));

					}catch (Exception e) {
						continue;
					}
					
				//Parallelogram case
				}else if((shapeParts[0].equals("Parallelogram"))){
					try{
						
						Parallelogram newParallelogram = new Parallelogram();
						
						double tempLength = Double.parseDouble(shapeParts[1]);
						double tempWidth = Double.parseDouble(shapeParts[2]);
						if(tempLength > 0 && tempWidth > 0){
							newParallelogram.setLength(tempLength);
							newParallelogram.setWidth(tempWidth);
							currentCount++;
						}
						else{
							System.out.println("This parallelogram has invalid values => l=" + tempLength + " ,w=" + tempWidth);
							continue;
						}
						
						System.out.println("Parallelogram --> { l = " + shapeParts[1] + " w = " + shapeParts[2] + " } perimeter = " + f.format(newParallelogram.perimeter()));

						//Adding to the total
						totalParallelogramPer += newParallelogram.perimeter();

					}catch (Exception e) {
						continue;
					}

				}else if((shapeParts[0].equals("Triangle"))){
					
					try{
						Triangle newTriangle = new Triangle();
						
						double tempSideA = Double.parseDouble(shapeParts[1]);
						double tempSideB = Double.parseDouble(shapeParts[3]);
						double tempBase = Double.parseDouble(shapeParts[2]);
						
						if(tempSideA > 0 && tempSideB > 0 && tempBase > 0){
							newTriangle.setSide1(tempSideA);
							newTriangle.setSide2(tempSideB);
							newTriangle.setBase(tempBase);
							currentCount++;
						}
						else{
							System.out.println("This triangle has invalid values => a=" + tempSideA + " ,b=" + tempBase + " ,c=" + tempSideB);
							continue;
						}
						
						System.out.println("Triangle -------> { a = " + shapeParts[1] + " b = " + shapeParts[2] + " c = " + shapeParts[3] + "  } perimeter = " + f.format(newTriangle.perimeter()));
						
						//Adding to the total 
						totalTrianglePer += newTriangle.perimeter();

						//If current perimeter is lower it will become the minimum
						if(newTriangle.perimeter() <= triangleMinimum){
							triangleMinimum =  newTriangle.perimeter();
						}


					}catch (Exception e) {
						continue;
					}

				//When it hit the END Line
				}else if(shapeParts[0].equals("END")){
					System.out.println("==> End of the file <==");
					break;
				}
				//Case for different named values
				else{
					System.out.println(" !----- " + shapeParts[0] + " is NOT an acceptable figure -----!" );
				}
			}

		}
		//Current Shape Count
		System.out.println("\nCurrent Shapes:" + currentCount);
		
		//Task 2
		System.out.println("\n=========> Task 2 <==========\n");
		int removedCount = 0;
		String[] checkShapeDetails = new String[55];
		int y = 0;
		String[] newTriangle = new String[55];
		
		//Loop through the current shapeArray
		
		for (String s1: shapeArray) {
			if(s1 != null){
				String[] shapeParts = s1.split(",");

				if(shapeParts[0].equals("Triangle")){
					
					Triangle comparisonTriangle = new Triangle();
					comparisonTriangle.setSide1(Double.parseDouble(shapeParts[1]));
					comparisonTriangle.setBase(Double.parseDouble(shapeParts[2]));
					comparisonTriangle.setSide2(Double.parseDouble(shapeParts[3]));
					
					
					//If the perimeter is equal we will remove it
					if(comparisonTriangle.perimeter() == triangleMinimum){
						removedCount++;
						System.out.println("Deleted Triangle ==> Values:" + s1.toString() +"  ----->  Perimeter:" + comparisonTriangle.perimeter());

					}else{
						checkShapeDetails[y] = s1;
						y++;
					}
				}else if(shapeParts[0].equals("Circle")){
					double radius = Double.parseDouble(shapeParts[1]);
					Circle comparisonCircle = new Circle();
					comparisonCircle.setRadius(radius);
					
					//If the perimeter is equal we will remove it
					if(comparisonCircle.perimeter() == circleMaximum){
						removedCount++;
						System.out.println("Deleted Circle ====> Values:" + s1.toString() +"  ----->  Perimeter:" + comparisonCircle.perimeter());

					}else{
						checkShapeDetails[y] = s1;
						y++;
					}

				}else{
					checkShapeDetails[y] = s1;
					y++;
				}
				for(String s2: newTriangle){
					checkShapeDetails[y] = s2;
				}
			}
		}
		
		//Removed Shape Count
		System.out.println("\nRemoved Shapes:" + removedCount);
		
		
		
		//Printing remanining shapes
		System.out.println("\n===> Remaining Shapes <=== \n");
		int remainedCount = 0;
		for(String z: checkShapeDetails){

			if(z != null){
				
				String[] shapeParts = z.split(",");
				
				if(shapeParts[0].equals("Circle")){
					double tempRadius = Double.parseDouble(shapeParts[1]);
					Circle reprintCircle = new Circle();
					if(tempRadius>0){
						reprintCircle.setRadius(tempRadius);
						remainedCount ++;
					}
					else{
						continue;
					}
					
					System.out.println("Circle ---------> { r = " + shapeParts[1] + " } perimeter = " + f.format(reprintCircle.perimeter()));
					
					
				}else if(shapeParts[0].equals("Square")){
					try{
						double tempLength = Double.parseDouble(shapeParts[1]);
						Square reprintSquare = new Square();
						if(tempLength>0){
							reprintSquare.setLength(tempLength);
							remainedCount ++;
						}
						else{
							continue;
						}
						
						
						System.out.println("Square ---------> { l = " + shapeParts[1] + " } perimeter = " + f.format(reprintSquare.perimeter()));

					}catch (Exception e) {
						
						continue;
					}
				}else if((shapeParts[0].equals("Rectangle"))){
					try{
						double tempLength = Double.parseDouble(shapeParts[1]);
						double tempWidth = Double.parseDouble(shapeParts[2]);
						Rectangle reprintRectangle = new Rectangle();
						if(tempLength > 0 && tempWidth >0){
							reprintRectangle.setLength(tempLength);
							reprintRectangle.setWidth(tempWidth);
							remainedCount ++;
						}
						else{
							continue;
						}
						

						System.out.println("Rectangle ------> { l = " + shapeParts[1] + " w = " + shapeParts[2] + " } perimeter = " + f.format(reprintRectangle.perimeter()));

					}catch (Exception e) {
						
						continue;
					}
				}else if((shapeParts[0].equals("Parallelogram"))){
					try{
						double tempLength = Double.parseDouble(shapeParts[1]);
						double tempWidth = Double.parseDouble(shapeParts[2]);
						Parallelogram reprintParallelogram = new Parallelogram();
						if(tempLength > 0 && tempWidth > 0){
							reprintParallelogram.setLength(tempLength);
							reprintParallelogram.setWidth(tempWidth);
							remainedCount ++;
						}
						else{
							continue;
						}
						
						System.out.println("Parallelogram --> { l = " + shapeParts[1] + " w = " + shapeParts[2] + " } perimeter = " + f.format(reprintParallelogram.perimeter()));

						totalParallelogramPer += reprintParallelogram.perimeter();

					}catch (Exception e) {
						continue;
					}

				}else if((shapeParts[0].equals("Triangle"))){
					try{
						double tempSideA = Double.parseDouble(shapeParts[1]); 
						double tempBase = Double.parseDouble(shapeParts[2]);
						double tempSideB = Double.parseDouble(shapeParts[3]);
						Triangle reprintTriangle = new Triangle();
						
						if(tempSideA > 0 && tempBase> 0 && tempSideB > 0){
							reprintTriangle.setSide1(tempSideA);
							reprintTriangle.setSide2(tempSideB);
							reprintTriangle.setBase(tempBase);
							remainedCount ++;
						}
						else{
							continue;
						}
						
						System.out.println("Triangle -------> { a = " + shapeParts[1] + " b = " + shapeParts[2] + " c = " + shapeParts[3] + "  } perimeter = " + f.format(reprintTriangle.perimeter()));
						totalTrianglePer += reprintTriangle.perimeter();

						if(reprintTriangle.perimeter() <= triangleMinimum){
							triangleMinimum =  reprintTriangle.perimeter();
						}


					}catch (Exception e) {
						continue;
					}
				}
			}
		}
		System.out.println("\nRemained Shapes:" + remainedCount);

		System.out.println("\n=========> Task 3 <==========\n");
		
		System.out.println("Perimeter Parallelogram Totals: "+ f.format(totalParallelogramPer));
		System.out.println("Perimeter Triangle Totals: "+ f.format(totalTrianglePer));
		
		System.out.println("\n=========> END <==========\n");
		
		

	}
	

}
