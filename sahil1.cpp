#include<iostream>
using namespace std;


class Scheduler
{
	private:
		int rq[400],r;
		int n,bt[20],wt[20],tat[20],at[20],time[100],tm,ct[20],avwt,avtat,i,j,flag,tq,max_at,max_at_1;
		
	public:
		void input()
		{
			cout<<"\nEnter Number of processes(max upto 20): ";
			cin>>n;
			if(n>20)
		 	tq=6;
			cout<<"\nEnter Burst Time: ";		// Burst Time
			for(i=1;i<=n;i++)
		    {
		        cout<<"\nP["<<i<<"] : ";
		        cin>>bt[i];
		    }
			
			cout<<"\n Note: arrival time should not contain '0' ";	
			cout<<"\n\nEnter Arrival Time in increasing order\n";	// Arrival Time
			for(i=1;i<=n;i++)
		    {
		        cout<<"\nP["<<i<<"] : ";
		        cin>>at[i];
		    }
		    
		    max_at=at[n];
		    max_at_1=at[n-1];
			flag=at[1];		// flag is equal to first arrival time
			tq=6;
		}
					
		void RR6()
		{
			for(i=1;i<=n;i++)	// checking for least arrival time
			{
				if(flag>at[i])
					flag=at[i];	// Min value of arrival time 
			}

			for(i=1;i<=n;i++)
			{
				if(flag==at[i])
				{
					r=1;
					rq[r]=i;	// 1 process in ready queue....
					cout<<"\nProcess P["<<i<<"] is running for 6 units of time... ";
					bt[i]=bt[i]-6;
					tm+=6;
					for(j=1;j<=n;j++)
					{
						if(at[j]<=6*j)
						{
							rq[r]=i;
							r++;
							break;
						}
						else
							{
								bt[i]=bt[i]-6;
								tm+=6;
							}
					}
				}
			}
				tq=10;
				cout<<"\nProcess interupted.... Time quantum changing to 10 !!!!";
		}

		void calculation()
		{
				for(i=1;i<=n;i++)	//calculating turnaround time
		    {
		        tat[i]=ct[i]-at[i];
		    }
		    
			for(i=1;i<=n;i++) // Waiting time
			{
				wt[i]=tat[i]-bt[i];
			}
		}
		
		void print_table()
		{
			cout<<"\nProcess\t\tArrival\t\tBurst\t\tWaiting\t\tTurnAround";	// Printing table
			for(i=1;i<=n;i++)
		    {
		    	cout<<"\nP["<<i<<"]\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
			}
		}
		
		void RR10()
		{
			for(i=2;i<=n;)
			{
				if(at[i]=max_at)
				{
					bt[i]=bt[i]-10;
					tm+=10;	
					rq[r]=i;
					r++;
					if(at[i]==max_at_1)
					{
						i=1;
						continue;
					}
					i++;
				}
			}
			
			cout<<"\nSince all process are arrived so, scheduling is going to be max according to burst time....";
		}
		
		void Burst_time()
		{
			flag=bt[1];
			for(i=1;i<=n;i++)
			{
				if(bt[i]<flag)
				{
					flag=i;
				}
			}
			for(i=flag;i<=n;i++)
			while(bt[flag]!=0)
			{
				tm=+bt[i];
				rq[r]=i;
				ct[i]=tm;
				cout<<"Process P[ "<<i<<" ] is going to terminate executed successfully... ";
			}
		}
	
		
};
int main()
{
    Scheduler obj;
	obj.input();
	obj.RR6(); 
	obj.RR10();
	obj.Burst_time();
	obj.calculation();
	obj.print_table();
    return 1;
}

